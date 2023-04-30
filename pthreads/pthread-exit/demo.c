#include <stdlib.h>
#include<unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* roll_dice() {
    int value = (rand() % 6) + 1;
    int* result = malloc(sizeof(int));
    *result = value;
    // sleep(2);
    printf("Thread result: %d\n", value);
    pthread_exit((void*) result);
}

int main(int argc, char* argv[]) {
    int* res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }
    //return 0; // if we uncomment this line then nothing will get printed
    // because peocess owns the thread
    // if there is no process , then there will not be any thread
    // pthread_exit(0);
    if (pthread_join(th, (void**) &res) != 0) {
        return 2;
    }
    printf("Result: %d\n", *res);
    free(res);
    return 0;
}