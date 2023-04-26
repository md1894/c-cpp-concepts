#include<iostream>
using namespace std;

void bubble_sort(int *array, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(array[j] > array[j+1]){
                std::swap(array[j], array[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = { 5, 1, 4, 2, 8};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, N);
    for(auto a : arr){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}