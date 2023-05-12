/*
In the pthreads API, a barrier is a synchronization mechanism that enables multiple threads 
to synchronize with each other at a specific point in their execution. 
A barrier ensures that a group of threads wait for each other to reach a certain point in their 
execution before proceeding further.

A barrier consists of a counter and a threshold value. 
When a thread reaches the barrier, it increments the counter, and then waits until the 
counter reaches the threshold value. Once the threshold value is reached, all threads waiting 
at the barrier are released, and can proceed with their execution.

The pthreads API provides a set of functions for creating and using barriers, 
including pthread_barrier_init(), pthread_barrier_wait(), and pthread_barrier_destroy(). 
These functions allow you to initialize a barrier, wait for threads to reach the barrier, 
and destroy the barrier when it is no longer needed.

Barriers can be useful in situations where multiple threads need to coordinate their execution, 
such as in parallel algorithms or simulations. By using a barrier, you can ensure that all threads 
have reached a certain point in their execution before proceeding, which can help to avoid 
race conditions and synchronization issues.

One important thing to note is that the pthreads barrier only synchronizes threads within a 
single process. If you need to synchronize threads across multiple processes, you will need to 
use a different synchronization mechanism, such as a message passing or shared memory.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_barrier_t barrier;

void* routine(void* args) {
    // while (1) {
        printf("Waiting at the barrier...\n");
        //sleep(1);
        pthread_barrier_wait(&barrier);
        printf("We passed the barrier\n");
        //sleep(1);
    // }
}

int main(int argc, char *argv[]) {
	pthread_t th[10];
	int i;
    pthread_barrier_init(&barrier, NULL, 2);
	for (i = 0; i < 10; i++) {
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
			perror("Failed to create thread");
		}
	}
	for (i = 0; i < 10; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join thread");
		}
	}
    pthread_barrier_destroy(&barrier);
	return 0;
}

/*
Waiting at the barrier...
Waiting at the barrier...
We passed the barrier
We passed the barrier
Waiting at the barrier...
Waiting at the barrier...
We passed the barrier
We passed the barrier
Waiting at the barrier...
Waiting at the barrier...
We passed the barrier
We passed the barrier
Waiting at the barrier...
Waiting at the barrier...
We passed the barrier
We passed the barrier
Waiting at the barrier...
Waiting at the barrier...
We passed the barrier
We passed the barrier

*/