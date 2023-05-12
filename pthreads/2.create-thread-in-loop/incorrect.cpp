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

    for(int i = 0; i < 8; i++){
        pthread_create(&th[i], NULL, routine, NULL);
        cout << "Thread no " << i << " Started " << endl;
        pthread_join(th[i], NULL);
        cout << "Thread no " << i << " Finished " << endl;
    }

    return 0;
}


/*
output of above program is 

Thread no 0 Started 
Thread no 0 Finished 
Thread no 1 Started 
Thread no 1 Finished 
Thread no 2 Started 
Thread no 2 Finished 
Thread no 3 Started 
Thread no 3 Finished 
Thread no 4 Started 
Thread no 4 Finished 
Thread no 5 Started 
Thread no 5 Finished 
Thread no 6 Started 
Thread no 6 Finished 
Thread no 7 Started 
Thread no 7 Finished 

There is no use of creating threads , one thread is started 

*/










