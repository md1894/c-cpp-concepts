/*
 * this will be the output of the program
 * it shows that same variable x is shared between 2 threads
 *
 * thread1 incremented value of x from 5 to 6
 * thread2 when accesses x , it has the value that is modified by thread1
 *
 * output--> 
 *
 * Value of x is : 6
 * Value of x is : 6
*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int x = 5;

void* routine1(){
	x++;
	sleep(2);
	printf("Value of x is : %d\n", x);
	return NULL;
}

void* routine2(){
	sleep(2);
	printf("Value of x is : %d\n", x);
	return NULL;
}


int main(){
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &routine1, NULL);
	pthread_create(&thread2, NULL, &routine2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
