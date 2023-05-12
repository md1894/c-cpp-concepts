#include<iostream>
#include<pthread.h>
using namespace std;

int a[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* printPrime(void *data){
    int *index = (int*) data;
    cout << a[*index] << " ";
    delete index;
    return NULL;
}

int main(){
    pthread_t th [10];
    for(int i = 0; i < 10; i++){
        int *a = new int;
        *a = i;
        if(pthread_create(&th[i], NULL, printPrime, (void*) a) != 0){
            perror("Error in creating thread");
        }
    }
    for(int i = 0; i < 10; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("Error in join thread");
        }
    }
    return 0;
}

/*
output :
this is because of thread context switching
23  5 7 11 13 17 19 23 29

run it again
2 5 3 11 7 13 17 19 23 29
*/