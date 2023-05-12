#include<iostream>
#include<pthread.h>
using namespace std;

pthread_mutex_t lock;
int a = 150;

void* routine(void* data){
    char *status = (char*)"OK STATUS";
    for(int i = 0; i < 1000000; i++){
        pthread_mutex_lock(&lock);
        a++;
        pthread_mutex_unlock(&lock);
    }
    return /*pthread_exit(status)*/NULL;
}

int main(){

    pthread_t th [8];

    /// now this is the multithreading effect
    for(int i = 0; i < 8; i++){
        pthread_create(&th[i], NULL, routine, NULL);
        cout << "Thread no " << i << " Started " << endl;
    }

    for(int i = 0; i < 8; i++){
        pthread_join(th[i], NULL);
        cout << "Thread no " << i << " Finished " << endl;
    }

    return 0;
}











