#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

int n;
int num = 1;
pthread_mutex_t lock;
pthread_cond_t condition_var;

void* print_odd(void *data){
    while(num <= n){
        pthread_mutex_lock(&lock);
        if(num % 2 != 0){
            cout << "(O)Number is " << num << endl;
            sleep(1);
            num++;
            pthread_mutex_unlock(&lock);
            pthread_cond_broadcast(&condition_var);
        }else{
            pthread_cond_wait(&condition_var, &lock);
        }
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

void* print_even(void *data){
    while(num <= n){
        pthread_mutex_lock(&lock);
        if(num % 2 == 0){
            cout << "(E)Number is " << num << endl;
            sleep(1);
            num++;
            pthread_mutex_unlock(&lock);
            pthread_cond_broadcast(&condition_var);
        }else{
            pthread_cond_wait(&condition_var, &lock);
        }
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main(){
    
    pthread_t even_print_thread, odd_print_thread;

    cout << "Enter number in the range 1 to 1000" << endl;
    cin >> n;
    if(n <= 0){
        perror("wrong input given , must be greater than equal to 1\n");
    }
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&condition_var, NULL);
    pthread_create(&odd_print_thread, NULL, print_odd, NULL);
    pthread_create(&even_print_thread, NULL, print_even, NULL);
    pthread_join(odd_print_thread, NULL);
    pthread_join(even_print_thread, NULL);
    pthread_cond_destroy(&condition_var);
    pthread_mutex_destroy(&lock);
    return 0;
}