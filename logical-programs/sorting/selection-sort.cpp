#include<iostream>
using namespace std;

void selection_sort(int *array, int n){
    int min_idx = 0;
    int i, j;
    for(i = 0; i < n-1; i++){
        min_idx = i;
        for(j = i+1; j < n; j++){
            if(array[j] < array[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i){
            std::swap(array[i], array[min_idx]);
        }
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    for(auto n : arr){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}