/*
so in this problem
we have 10 chefs , and we have multiple stove
we have to make each chef can cook his/her food on any of the stove
only once
*/

#include<iostream>
#include<time.h>
#include<pthread.h>
#include<unistd.h>
using namespace std;

pthread_mutex_t stove_lock[4];
int stove_gas[4] = {100, 100, 100, 100};

void *cook(void *data){
    for(int i = 0; i < 4; i++){
        if(pthread_mutex_trylock(&stove_lock[i]) == 0){
            int fuelNeeded = (rand() % 30);
            if (stove_gas[i] - fuelNeeded < 0) {
                printf("No more fuel... going home\n");
            } else {
                stove_gas[i] -= fuelNeeded;
                usleep(500000);
                printf("Fuel left %d\n", stove_gas[i]);
            }
            pthread_mutex_unlock(&stove_lock[i]);
            break;
        }else{
            if(i == 3){
                cout << "No stove available yet, waiting...\n";
                usleep(300000);
                i = 0;
            }
        }
    }
    pthread_exit(NULL);
}

int main(){
    srand(time(NULL));
    pthread_t chefs[10];
    for(int i = 0; i < 4; i++){
        pthread_mutex_init(&stove_lock[i], NULL);
    }
    for(int i = 0; i < 10; i++){
        if(pthread_create(&chefs[i], NULL, cook, NULL) != 0){
            perror("Error in creating thread\n");
        }
    }
    for(int i = 0; i < 10; i++){
        pthread_join(chefs[i], NULL);
    }
    for(int i = 0; i < 4; i++){
        pthread_mutex_destroy(&stove_lock[i]);
    }
    return 0;
}