#include<iostream>
using namespace std;

void merge(int *array, int left, int mid, int right){
    int temp[right+1];
    int left_start = left;
    int left_end = mid;
    int right_start = mid + 1;
    int right_end = right;
    int k = 0;

    while(left_start <= left_end && right_start <= right_end){
        if(array[left_start] < array[right_start]){
            temp[k++] = array[left_start++];
        }else{
            temp[k++] = array[right_start++];
        }
    }

    while(left_start <= left_end){
        temp[k++] = array[left_start++];
    }

    while(right_start <= right_end){
        temp[k++] = array[right_start++];
    }

    for(int i = left; i < right+1; i++){
        array[i] = temp[i-left];
    }

}

void mergeSort(int *array, int start, int end){
    if(start < end){
        int mid = (start+end)/2;
        mergeSort(array, start, mid);
        mergeSort(array, mid+1, end);
        merge(array, start, mid, end);
    }
}

int main(){
    int a[] = {2,4,1,6,8,5,3,7};
    int n = 8;
    mergeSort(a,0,7);
    for(auto n : a){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}