#include<iostream>
using namespace std;

void insertion_sort(int *array, int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(array[j-1] > array[j]){
                std::swap(array[j-1], array[j]);
            }
        }
    }
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, N);
    for(auto n : arr){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}