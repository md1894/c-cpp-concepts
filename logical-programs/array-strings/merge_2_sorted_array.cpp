/*
Given two sorted arrays, the task is to merge them in a sorted manner.

Input: arr1[] = { 1, 3, 4, 5}, arr2[] = {2, 4, 6, 8} 
Output: arr3[] = {1, 2, 3, 4, 4, 5, 6, 8}

Input: arr1[] = { 5, 8, 9}, arr2[] = {4, 7, 8} 
Output: arr3[] = {4, 5, 7, 8, 8, 9} 


*/

#include<iostream>
using namespace std;

void merge_arrays(int a[], int an, int b[], int bn, int c[], int cn){
    int i = 0, j = 0, k = 0;
    while(i < an && j < bn){
        if(a[i] < b[j]){
            c[k++] = a[i++];
        }else{
            c[k++] = b[j++];
        }
    }

    // if any left-over elements remaining in array : a
    while(i < an){
        c[k++] = a[i++];
    }
    // if any left-over elements remaining in array : b
    while(j < bn){
        c[k++] = b[j++];
    }
}

int main(){
    /// test case 1
    /*
    int a1[] = {1,3,4,5};
    int a2[] = {2,4,6,8};
    int an1 = 4, an2 = 4;
    int a3[8], an3 = an1+an2;
    */

   /// test case 2
    int a1[] = {5, 8, 9};
    int a2[] = {4, 7, 8};
    int an1 = 3, an2 = 3;
    int a3[6], an3 = an1+an2;

    merge_arrays(a1, an1, a2, an2, a3, an3);
    for(int i = 0; i < an3; i++){
        cout << a3[i] << endl;
    }
    return 0;
}