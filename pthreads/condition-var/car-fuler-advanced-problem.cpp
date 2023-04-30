#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

pthread_mutex_t update_fuel_level;
pthread_cond_t wait_for_fuel;

int fuel_level = 0;

void *fill_fuel(void *data){
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&update_fuel_level);
        fuel_level += 60;
        // sleep(1);
        cout << "Fuel Level Updated , Level : " << fuel_level << endl;
        pthread_mutex_unlock(&update_fuel_level);
        pthread_cond_signal(&wait_for_fuel);
    }
    pthread_exit(NULL);
}

void *consume_fuel(void *data){
    pthread_mutex_lock(&update_fuel_level);
    while(fuel_level < 40){
        cout << "Waiting For Fuel ..." << endl;
        pthread_cond_wait(&wait_for_fuel, &update_fuel_level);
    }
    fuel_level -= 40;
    sleep(1);
    cout << "Got Fuel , Fuel Level is " << fuel_level << endl;
    pthread_mutex_unlock(&update_fuel_level);
    pthread_exit(NULL);
}

int main(){
    pthread_t thread_pool[6];
    pthread_mutex_init(&update_fuel_level,  NULL);
    pthread_cond_init(&wait_for_fuel, NULL);
    for(int i = 0; i < 6; i++){
        if(i == 5){
            pthread_create(&thread_pool[i], NULL, fill_fuel, NULL);
        }else{
            pthread_create(&thread_pool[i], NULL, consume_fuel, NULL);
        }
    }
    for(int i = 0; i < 6; i++){
        pthread_join(thread_pool[i], NULL);
    }
    pthread_mutex_destroy(&update_fuel_level);
    pthread_cond_destroy(&wait_for_fuel);
    return 0;
}

/*
Waiting For Fuel ...
Waiting For Fuel ...
Waiting For Fuel ...
Waiting For Fuel ...
Waiting For Fuel ...
Fuel Level Updated , Level : 15
Fuel Level Updated , Level : 30
Fuel Level Updated , Level : 45
Got Fuel , Fuel Level is 5
Waiting For Fuel ...
Waiting For Fuel ...
Fuel Level Updated , Level : 20
Fuel Level Updated , Level : 35
Fuel Level Updated , Level : 50
Fuel Level Updated , Level : 65
Fuel Level Updated , Level : 80
Fuel Level Updated , Level : 95
Fuel Level Updated , Level : 110
Got Fuel , Fuel Level is 70
Got Fuel , Fuel Level is 30
Waiting For Fuel ...
Waiting For Fuel ...
*/

/*
observe line no 65, 66
actually there are total 5 cars which require fueling
one has got fuel , so 5 must be waiting for fuel
from output it is observed that only 2 threads got the signal
pthread_cond_signal gives signal to a single thread at a time
to avoid such situation we can use 
pthread_cond_broadcast function

it may happen that instead of 15 , fuel is getting filled in a large step
like 80, so it can fuel 2 cars in one single go, just change the updation and observe the
change
*/

/*
Waiting For Fuel ...
Waiting For Fuel ...
Fuel Level Updated , Level : 60 // here one of the car can be filled
Fuel Level Updated , Level : 120
Fuel Level Updated , Level : 180
Fuel Level Updated , Level : 240
Got Fuel , Fuel Level is 200
Got Fuel , Fuel Level is 160
Got Fuel , Fuel Level is 120
Got Fuel , Fuel Level is 80
Got Fuel , Fuel Level is 40
Fuel Level Updated , Level : 100
Fuel Level Updated , Level : 160
Fuel Level Updated , Level : 220
Fuel Level Updated , Level : 280
Fuel Level Updated , Level : 340
Fuel Level Updated , Level : 400
*/

/*
Waiting For Fuel ...
Waiting For Fuel ...
Waiting For Fuel ...
Waiting For Fuel ...
Fuel Level Updated , Level : 60
Fuel Level Updated , Level : 120
Fuel Level Updated , Level : 180
Fuel Level Updated , Level : 240
Got Fuel , Fuel Level is 200
Fuel Level Updated , Level : 260 // we can fill other cars tank
Got Fuel , Fuel Level is 220
Got Fuel , Fuel Level is 180
Got Fuel , Fuel Level is 140
Got Fuel , Fuel Level is 100
Fuel Level Updated , Level : 160
Fuel Level Updated , Level : 220
Fuel Level Updated , Level : 280
Fuel Level Updated , Level : 340
Fuel Level Updated , Level : 400
*/