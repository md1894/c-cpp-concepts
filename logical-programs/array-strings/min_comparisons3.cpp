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
Maximum and minimum of an array by comparing in pairs:
If n is odd then initialize min and max as the first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For the rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively. 

Below is the implementation of the above approach:

analysis : for comparing 2 element we need to perform only 3 comparisons 
whereas in normal method we need to compare a single element twice 

*/

#include<iostream>
using namespace std;

struct Pair {
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n) {

    struct Pair minmax;

    int i = 0;
    if(n%2 == 0){
        if(arr[i] > arr[i+1]){
            minmax.max = arr[i];
            minmax.min = arr[i+1];
        }else{
            minmax.max = arr[i+1];
            minmax.min = arr[i];
        }
        i+=2;
    }else{
        minmax.max = arr[i];
        minmax.min = arr[i];
        i+=1;
    }

    while(i < n-1){
        if(arr[i] < arr[i+1]){
            if(arr[i] < minmax.min)
                minmax.min = arr[i];
            if(arr[i+1] > minmax.max)
                minmax.max = arr[i+1];
        }else{
            if(arr[i] > minmax.max)
                minmax.max = arr[i];
            if(arr[i+1] < minmax.min)
                minmax.min = arr[i+1];
        }
        i += 2;
    }
    return minmax;
}

int main(){

    int arr[] = { 1000, 11, 445, 
                1, 330, 3000 }; 
    int arr_size = 6; 
      
    Pair minmax = getMinMax(arr, arr_size); 
      
    cout << "Minimum element is "
        << minmax.min << endl; 
    cout << "Maximum element is "
        << minmax.max; 
          
    return 0; 
}