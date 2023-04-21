#include<iostream>
#include<pthread.h>
using namespace std;

pthread_mutex_t lock;

int i = 1000000;

void* routine(void *data){
    
    for(int a = 0; a < 1000000; a++){
        pthread_mutex_lock(&lock);
        i++;
        pthread_mutex_unlock(&lock);
    }
    cout << "Thread " << (char*)data << " Finished Actually " << endl;
    pthread_exit(NULL);
}


int main(){
    pthread_t th[8];
    char thread_name [8] [15];
    for(int i = 0; i < 8; i++){
        sprintf(thread_name[i], "%d", i+1);
    }
    pthread_mutex_init(&lock, NULL);
    for(int i = 0; i < 8; i++){
        if(pthread_create(&th[i], NULL, routine, (void*) thread_name[i]) != 0){
            perror("error in creating thread");
            exit(0);
        }
    }
    for(int i = 0; i < 8; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("error in joining thread");
            exit(0);
        }
        cout << "Thread no " << i+1 << " Finished " << endl;
    }
    cout << "Final Output is " << i << endl;
    pthread_mutex_destroy(&lock);
    return 0;
}

/*
it is not compulsory that each thread will finish its execution in the sequence 
of calling join , observe output carefully
*/

/*
Thread 1 Finished Actually 
Thread no 1 Finished 
Thread 2 Finished Actually 
Thread no 2 Finished 
Thread 7 Finished Actually 
Thread 8 Finished Actually 
Thread 6 Finished Actually 
Thread 5 Finished Actually 
Thread 3 Finished Actually 
Thread no 3 Finished 
Thread 4 Finished Actually 
Thread no 4 Finished 
Thread no 5 Finished 
Thread no 6 Finished 
Thread no 7 Finished 
Thread no 8 Finished 
Final Output is 9000000

*/