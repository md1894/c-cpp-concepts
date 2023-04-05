/*
Sort an array of 0s, 1s and 2s | Dutch National Flag problem

Input: {0, 1, 2, 0, 1, 2}
Output: {0, 0, 1, 1, 2, 2}

Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

There are 3 flags :--> low, mid, high

there are 3 conditions 
    1. when arr[mid] == 0
    2. when arr[mid] == 1
    3. when arr[mid] == 2

init 
    low, mid --> 0 index
    high --> n-1 index

*/

#include<iostream>
using namespace std;

int main(){
    int arr [] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = 12;
    int low = 0, mid = 0;
    int high = n-1;

    while(mid <= high){
        if(arr[mid] == 0){
            std::swap(arr[low++], arr[mid++]);
        }else if(arr[mid] == 1){
            mid++;
        }else if(arr[mid] == 2){
            std::swap(arr[mid], arr[high--]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}