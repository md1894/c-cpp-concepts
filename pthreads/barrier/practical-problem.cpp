#include<iostream>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;

#define NUM_THREAD 8

int status[NUM_THREAD] = {0};
int dice_values[NUM_THREAD];

pthread_barrier_t roll_dice_barrier;
pthread_barrier_t calculate_winner;

void* roll_dice(void *data){
    int index = *(int*) data;
    dice_values[index] = rand() % 6 + 1;
    pthread_barrier_wait(&roll_dice_barrier);
    pthread_barrier_wait(&calculate_winner);
    if(status[index] == 1){
        cout << index << " Rolled " << dice_values [index] << " He won " << endl;
    }else{
        cout << index << " Rolled " << dice_values [index] << " He lost " << endl;
    }
    delete (int*)data;
    pthread_exit(NULL);
}


int main(){
    srand(time(NULL));
    pthread_t th[NUM_THREAD];

    pthread_barrier_init(&roll_dice_barrier, NULL, NUM_THREAD + 1);
    pthread_barrier_init(&calculate_winner, NULL, NUM_THREAD + 1);
    for(int i = 0; i < NUM_THREAD; i++){
        int *a = new int(i);
        if(pthread_create(&th[i], NULL, roll_dice, (void*) a) != 0){
            perror("error in creating the thread");
        }
    }
    pthread_barrier_wait(&roll_dice_barrier);
    int max = 0;
    for(int i = 0; i < NUM_THREAD; i++){
        if(max < dice_values[i]){
            max = dice_values[i];
        }
    }

    for(int i = 0; i < NUM_THREAD; i++){
        if(dice_values[i] == max){
            status[i] = 1;
        }else{
            status[i] = 0;
        }
    }
    pthread_barrier_wait(&calculate_winner);
    for(int i = 0; i < NUM_THREAD; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("error in joining threads");
        }
    }
    pthread_barrier_destroy(&roll_dice_barrier);
    pthread_barrier_destroy(&calculate_winner);
    return 0;
}

/*
1 Rolled 4 He lost 
3 Rolled 6 He won 
4 Rolled 6 He won 
5 Rolled 1 He lost 
0 Rolled 5 He lost 
6 Rolled 3 He lost 
7 Rolled 2 He lost 
2 Rolled 3 He lost
*/