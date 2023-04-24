#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

int fuel_level = 0;
pthread_mutex_t lock;


void* fill_tank(void *data){
    pthread_mutex_lock(&lock);
    for(int i = 0; i < 15; i++){
        fuel_level += 15;
        cout << "Filling Fuel , current level is " << fuel_level << endl;
        sleep(1);
    }
    pthread_mutex_unlock(&lock);
    return 0;
}

void* consume_fuel(void *data){
    pthread_mutex_lock(&lock);
    fuel_level -= 40;
    cout << "Fuel Consumed , current fuel level is " << fuel_level << endl;
    sleep(1);
    pthread_mutex_unlock(&lock);
    return 0;
}

int main(){
    pthread_t fill_thread, consume_thread;
    pthread_mutex_init(&lock, NULL);
    for(int i = 0; i < 2; i++){
        if(pthread_create(i == 0 ? &fill_thread : &consume_thread, NULL, 
            i == 0 ? fill_tank : consume_fuel, NULL) != 0){
            perror("Error in creating tank filling thread");
        }
    }

    for(int i = 0; i < 2; i++){
        if(pthread_join(i == 0 ? fill_thread : consume_thread, NULL) != 0){
            perror("Error in joining threads");
        }
    }
    pthread_mutex_destroy(&lock);
    return 0;
}

/*

outputs before condition variable
kimaya@kimaya-System-Product-Name:~/Mehul/c-cpp-concepts/pthreads/condition-var$ ./a.out 
Filling Fuel , current level is 15
Filling Fuel , current level is 30
Filling Fuel , current level is 45
Filling Fuel , current level is 60
Filling Fuel , current level is 75
Filling Fuel , current level is 90
Filling Fuel , current level is 105
Filling Fuel , current level is 120
Filling Fuel , current level is 135
Filling Fuel , current level is 150
Filling Fuel , current level is 165
Filling Fuel , current level is 180
Filling Fuel , current level is 195
Filling Fuel , current level is 210
Filling Fuel , current level is 225
Fuel Consumed , current fuel level is 185 /// for consuming atleast 40L fuel req
/// but have to wait till tank is filled 185L

kimaya@kimaya-System-Product-Name:~/Mehul/c-cpp-concepts/pthreads/condition-var$ ./a.out 
Fuel Consumed , current fuel level is -40 /// this is a problem, -40 ???
Filling Fuel , current level is -25
Filling Fuel , current level is -10
Filling Fuel , current level is 5
Filling Fuel , current level is 20
Filling Fuel , current level is 35
Filling Fuel , current level is 50
Filling Fuel , current level is 65
Filling Fuel , current level is 80
Filling Fuel , current level is 95
Filling Fuel , current level is 110
Filling Fuel , current level is 125
Filling Fuel , current level is 140
Filling Fuel , current level is 155
Filling Fuel , current level is 170
Filling Fuel , current level is 185

*/