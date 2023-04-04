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

using tournament approach (recursive-approach)

*/

#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

struct Pair getMinMax(int a[], int low, int high){
    struct Pair minmax, mml, mmr;
    int mid;

    if(high == low){
        minmax.min = a[0];
        minmax.max = a[1];
        return minmax;
    }

    if(high == low + 1){
        if(a[0] > a[1]){
            minmax.min = a[1];
            minmax.max = a[0];
        }else {
            minmax.min = a[0];
            minmax.max = a[1];
        }
        return minmax;
    }

    mid = (high + low) / 2;
    mml = getMinMax(a, 0, mid);
    mmr = getMinMax(a, mid + 1, high);

    if(mml.min < mmr.min){
        minmax.min = mml.min;
    }else{
        minmax.min = mmr.min;
    }

    if(mml.max > mmr.max){
        minmax.max = mml.max;
    }else{
        minmax.max = mmr.max;
    }

    return minmax;

}

int main(){
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int arr_size = 6;
    struct Pair minmax = getMinMax(arr, 0, arr_size - 1);
    printf("nMinimum element is %d\n", minmax.min);
    printf("nMaximum element is %d\n", minmax.max);
    return 0;
}