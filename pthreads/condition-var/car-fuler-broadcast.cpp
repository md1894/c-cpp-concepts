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
        fuel_level += 15;
        // sleep(1);
        cout << "Fuel Level Updated , Level : " << fuel_level << endl;
        pthread_mutex_unlock(&update_fuel_level);
        pthread_cond_broadcast(&wait_for_fuel);
        sleep(1);
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
    // sleep(1);
    cout << "Got Fuel , Fuel Level is " << fuel_level << endl;
    pthread_mutex_unlock(&update_fuel_level);
    pthread_exit(NULL);
}

int main(){
    pthread_t thread_pool[6];
    pthread_mutex_init(&update_fuel_level,  NULL);
    pthread_cond_init(&wait_for_fuel, NULL);
    for(int i = 0; i < 6; i++){
        if(i == 4 || i == 5){
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
Fuel Level Updated , Level : 15
Fuel Level Updated , Level : 30
Waiting For Fuel ... // here you can see that signal passed to all consumers
Waiting For Fuel ...
Waiting For Fuel ...
Waiting For Fuel ...
Fuel Level Updated , Level : 45
Got Fuel , Fuel Level is 5
Waiting For Fuel ...
Waiting For Fuel ...
Fuel Level Updated , Level : 20
Waiting For Fuel ...
Waiting For Fuel ...
Waiting For Fuel ...
Fuel Level Updated , Level : 35
Fuel Level Updated , Level : 50
Got Fuel , Fuel Level is 10
Waiting For Fuel ... // 2 got fuel , then other two wakes up and checks weather fuel or not
Waiting For Fuel ...
Fuel Level Updated , Level : 25
Waiting For Fuel ...
Fuel Level Updated , Level : 40
Got Fuel , Fuel Level is 0
Waiting For Fuel ...
Fuel Level Updated , Level : 15
Fuel Level Updated , Level : 30
Waiting For Fuel ...
Fuel Level Updated , Level : 45
Fuel Level Updated , Level : 60
Got Fuel , Fuel Level is 20
Fuel Level Updated , Level : 35
Fuel Level Updated , Level : 50
Fuel Level Updated , Level : 65
Fuel Level Updated , Level : 80
Fuel Level Updated , Level : 95
Fuel Level Updated , Level : 110
Fuel Level Updated , Level : 125
Fuel Level Updated , Level : 140
*/