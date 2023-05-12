#include<iostream>
#include<pthread.h>
using namespace std;

int *fuel = nullptr;
pthread_barrier_t wait_for_deallocation;

void *update_fuel(void *data){
    *fuel += 50;
    cout << "(inside thread)Upated Value of Thread is " << *fuel << endl;
    pthread_barrier_wait(&wait_for_deallocation);
    return NULL;
}

int main(){
    pthread_t th;
    fuel = new int(50);
    pthread_barrier_init(&wait_for_deallocation, NULL, 2);
    pthread_create(&th, NULL, update_fuel, NULL);
    pthread_barrier_wait(&wait_for_deallocation);
    cout << "(inside main)Upated Value of Thread is " << *fuel << endl;
    if(fuel){
        cout << "De-allocating the memory " << endl;
        delete fuel;
        fuel = nullptr;
    }
    pthread_join(th, NULL);
    pthread_barrier_destroy(&wait_for_deallocation);
    return 0;
}


