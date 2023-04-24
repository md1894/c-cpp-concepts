#include<iostream>
#include<pthread.h>
using namespace std;

int a[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* print(void *data){
    int index = *(int *) data;
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += a[index + i];
    }
    *(int*) data = sum;
    pthread_exit(data);
}

int main(){
    pthread_t th[2];
    for(int i = 0; i < 2; i++){
        int *a = new int;
        *a = i * 5;
        if(pthread_create(&th[i], NULL, print, (void*)a) != 0){
            perror("Error in creating threads");
        }
    }
    int sum = 0;
    for(int i = 0; i < 2; i++){
        int *res;
        if(pthread_join(th[i], (void**) &res) != 0){
            perror("Error in joining threads");
        }
        sum += *res;
        delete res;
    }
    cout << "Sum is " << sum << endl;
    return 0;
}