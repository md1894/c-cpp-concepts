/*
`pthread_mutex_trylock()` is a function in the pthread library in C/C++ that is used to attempt 
to acquire a mutex lock without blocking. If the mutex lock is available, 
`pthread_mutex_trylock()` acquires the lock and returns immediately. 
If the mutex lock is not available, `pthread_mutex_trylock()` returns immediately with an error code 
indicating that the lock is already held by another thread.



In this example, `my_thread_function()` is a thread function that attempts to acquire a mutex lock 
using `pthread_mutex_trylock()`. If the lock is acquired, 
it increments a shared variable and then releases the lock using `pthread_mutex_unlock()`. 
If the lock is not acquired, it prints a message to the console.

The `main()` function creates two threads that both run `my_thread_function()`. 
After both threads have completed, `main()` prints the final value of 
the shared variable to the console.

Note that `pthread_mutex_trylock()` returns 0 if the lock is acquired, 
and returns a non-zero error code if the lock is not acquired. 
Therefore, we use an if-else statement to check the return value of `pthread_mutex_trylock()` 
and act accordingly.
*/

#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

pthread_mutex_t lock;

void* task(void *data){
    if(pthread_mutex_trylock(&lock) == 0){
        cout << "Got Lock" << endl;
        sleep(1);
        pthread_mutex_unlock(&lock);
    }else{
        cout << "No Entry" << endl;
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t th[4];
    pthread_mutex_init(&lock, NULL);
    for(int i = 0; i < 4; i++){
        if(pthread_create(&th[i], NULL, task, NULL) != 0){
            perror("Error in creating Threads");
        }
    }
    for(int i = 0; i < 4; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("Error in joining threads");
        }
    }
    pthread_mutex_destroy(&lock);
    return 0;
}

/*
each time you run you will get different outputs

Got Lock
No Entry
No Entry
No Entry

Got Lock
No EntryNo Entry
No Entry

No EntryNo Entry
No Entry
Got Lock
*/