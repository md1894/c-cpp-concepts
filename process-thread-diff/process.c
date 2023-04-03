/*
 * in this program it is clearly seen that for each process separate memory for variable x is there
 * hence it is proved that process do not share same memory like threads 
 *
 * output of program --> 
 *
 * Value of x is 5
 * Value of x is 20
 * */


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int x = 5;

int main(){
	int pid = fork();
	/*
	 * if pid == 0 , it means we are inside child process
	 * now child will modify the value of x
	 * */
	if(pid == 0){
		x += 15;
	}

	printf("Value of x is %d\n", x);
	return 0;
}
