#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;

/*
if i lock resource twice then there will be a deadlock
to overcome this we can use recursive mutex
*/

void* routine(void* args) {
    pthread_mutex_lock(&mutexFuel);// it locks
    pthread_mutex_lock(&mutexFuel);// waiting for this mutex forever
    fuel += 50;
    printf("Incremented fuel to: %d \n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexFuel, NULL);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    printf("Fuel: %d\n", fuel);
    pthread_mutex_destroy(&mutexFuel);
    return 0;
}