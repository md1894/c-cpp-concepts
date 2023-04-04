#include<iostream>
#include<pthread.h>
using namespace std;

static int shared{1000};
pthread_mutex_t lock;

/*
 * you can use mutex_guard for the case where you locked some resource but before unlocking any 
 * exception / segmentation fault / runtime error occurs so in that case my resource will be locked.
 *
 * to avoid this you can use mutex_guard , when it goes out of scope , automatically its destructor will call the unlock method and free that resource
 *
 * */

void* fun(void *data){
	char *status = (char*)"OK STATUS";
	for(int i = 0; i < 1000; i++){
		pthread_mutex_lock(&lock);
		++shared; /// critical section
		pthread_mutex_unlock(&lock);
	}
	//return NULL;
	pthread_exit(status);
}

int main(){
	pthread_t thread1;
	pthread_t thread2;
	void *ret;
	//fun(NULL);
	//fun(NULL);
	pthread_mutex_init(&lock, NULL);
	pthread_create(&thread1, NULL, fun, NULL);
	/**
	 * int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
	 * arg no 1 : pthread_t object address
	 * 
	 * arg no 2 : pthread_attr_t object reference (to set thread attributes like scope, detachstate, stacksize, priority, etc ...)
	 *            if passed NULL , then default thread attributes are used
	 * 
	 * arg no 3 : routine function pointer --> void *foo(void *);
	 * 
	 * arg no 4 : is the data that you can pass
	*/

	pthread_create(&thread2, NULL, fun, NULL);

	pthread_join(thread1, &ret);

	/**
	 * 	#define _UNIX03_THREADS
	 * 	#include <pthread.h>
	 * 
	 * int pthread_join(pthread_t thread, void **status);
	 * 
	 * status contains a pointer to the status argument passed by the ending thread as part of pthread_exit(). 
	 * If the ending thread terminated with a return, status contains a pointer to the return value. 
	 * If the thread was canceled, status can be set to -1.
	*/

	pthread_join(thread2, &ret);
	pthread_mutex_destroy(&lock);
	cout << "Value of Shared Value is " << shared << endl;
	cout << "Thread Exited With a Status " << (char*)ret << endl;

	return 0;
}
