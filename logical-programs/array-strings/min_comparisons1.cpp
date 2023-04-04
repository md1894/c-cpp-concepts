/*
Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

Examples:

Input: arr[] = {3, 5, 4, 1, 9}
Output: Minimum element is: 1
Maximum element is: 9

Input: arr[] = {22, 14, 8, 17, 35, 3}
Output:  Minimum element is: 3
Maximum element is: 35

*/

/*

using simple linear search

*/

#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

struct Pair calc_min_max(int a[], int n){
    struct Pair minmax;
    if(a[0] > a[1]){
        minmax.min = a[1];
        minmax.max = a[0];
    }else{
        minmax.min = a[0];
        minmax.max = a[1];
    }

    for(int i = 2; i < n; i++){
        if(a[i] < minmax.min){
            minmax.min = a[i];
        }
        else if(a[i] > minmax.max){
            minmax.max = a[i];
        }
    }
    return minmax;
}

int main(){
    int a[5] = {3,5,4,1,9};
    int b[6] = {22,14,8,17,35,3};

    struct Pair minmax = calc_min_max(a, 5);
    cout << "Min is " << minmax.min << " Max is " << minmax.max << endl;
    
    minmax = calc_min_max(b, 6);
    cout << "Min is " << minmax.min << " Max is " << minmax.max << endl;

    return 0;
}