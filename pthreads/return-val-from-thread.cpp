#include<iostream>
#include<pthread.h>
using namespace std;

int val = 1000;

pthread_mutex_t lock;

void *routine(void *data){
    int *res = (int*) malloc(sizeof(int));
    *res = 100;
    //pthread_exit((void*)res); /// this line is also OK
    return (void*)res;
}

int main(){
    int *res;
    pthread_t thread;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&thread, NULL, routine, NULL);
    pthread_join(thread, (void**) &res);
    cout << "Return Value from thread is " << *res << endl;
    pthread_mutex_destroy(&lock);
    free(res);
    return 0;
}