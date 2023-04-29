#include<iostream>
using namespace std;

void printSubArrayWithSum(int array[], int N, int S){
    int j = 0;
    int sum = 0;
    for(int i = 0; i < N; i++){
        if(sum < S){
            sum += array[i];
        }
        if(sum > S){
            while(sum > S){
                sum -= array[j++];
            }
        }
        if(sum == S){
            cout << j + 1 << " " << i + 1 << endl;
            return;
        }
    }
}

int main(){
    int N = 5, S = 12;
    int A[]{1,2,3,7,5};
    printSubArrayWithSum(A, N, S);
    return 0;
}