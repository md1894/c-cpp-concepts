/*
mutex holds an ownership
means it expects that if you acquire mutex_lock in a thread
then you must unlock that in same thread itself
otherwise it may result to undefined behaviour

whereas in case of semaphore , you can call wait on one thread
and post on any other thread , it is completely fine
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 4

pthread_mutex_t mutexFuel;
sem_t semFuel;
int fuel = 50;

void* routine1(void* args) {
    while (1) {
        //sem_wait(&semFuel);
        pthread_mutex_lock(&mutexFuel);
        fuel += 50;
        printf("Current value is %d\n", fuel);
    }
}

void* routine2(void* args) {
    while (1) {
        pthread_mutex_unlock(&mutexFuel);
        //sem_post(&semFuel);
        usleep(5000);
    }
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semFuel, 0, 1);
    pthread_mutex_init(&mutexFuel, NULL);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (i % 2 == 0) {
            if (pthread_create(&th[i], NULL, &routine1, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &routine2, NULL) != 0) {
                perror("Failed to create thread");
            }   
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    sem_destroy(&semFuel);
    return 0;
}