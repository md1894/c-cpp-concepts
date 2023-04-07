/*
Problem: Given a sorted array arr[] of n elements, 
write a function to search a given element x in arr[] and return the index of x in the array. 
Consider array is 0 base index.

Input: arr[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170}, x = 110
Output: 6
Explanation: Element x is present at index 6. 

Input: arr[] = {10, 20, 30, 40, 60, 110, 120, 130, 170}, x = 175
Output: -1
Explanation: Element x is not present in arr[].


*/


#include<iostream>
using namespace std;


int findTargetIterative(int A[] , int N, int X){
    int high = N-1, low = 0;
    while(high >= low){
        int mid = low+((high-low)/2);
        if(X == A[mid])
            return mid;
        else if(A[mid] < X){
            // target is present at the right side
            low = mid+1;
        }else if(A[mid] > X){
            // target is present at the left side
            high = mid-1;
        }
    }
    return -1;
}


int findTargetRecursive(int A[], int X, int low, int high){
    if(low > high)
        return -1;
    
    int mid = low + ((high-low)/2);

    if(X == A[mid])
        return mid;// target found
    else if(X > A[mid]) // target is present at the right side
        return findTargetRecursive(A, X, mid+1, high);
    else if(X < A[mid]) // target is present at the left side
        return findTargetRecursive(A, X, low, mid-1);
}

int main(){
    int A[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170};
    int x = 110, N = 10;

    int low = 0, high = N - 1;

    cout << "Target Element " << x << " is attached at index " << findTargetIterative(A, N, x) << endl;
    cout << "Target Element " << x << " is attached at index " << findTargetRecursive(A, x, low, high) << endl;
    return 0;
}