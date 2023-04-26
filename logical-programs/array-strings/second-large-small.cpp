/*
Example 1:
Input: [1,2,4,7,7,5]
Output: Second Smallest : 2
	Second Largest : 5
Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 
and second smallest is 2

Example 2:
Input: [1]
Output: Second Smallest : -1
	Second Largest : -1
Explanation: Since there is only one element in the array, it is the largest and 
smallest element present in the array. There is no second largest or 
second smallest element present.
*/

#include<iostream>
#include<climits>
using namespace std;

int secondLargest(int *array, int n){
    if(n < 2)
        return -1;
    
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    
    for(int i = 0; i < n; i++){
        if(array[i] > largest){
            second_largest = largest;
            largest = array [i];
        }else if(array[i] > second_largest && array[i] != largest){
            second_largest = array [i];
        }
    }

    return second_largest;
}

int secondSmallest(int *array, int n){
    if(n < 2)
        return -1;

    int smallest = INT_MAX;
    int second_smallest = INT_MAX;

    for(int i = 0; i < n; i++){
        if(array[i] < smallest){
            second_smallest = smallest;
            smallest = array [i];
        }else if(array[i] < second_smallest && array[i] != smallest){
            second_smallest = array [i];
        }
    }
    return second_smallest;
}


int main(){
    int arr[6]{1, 2, 4, 7, 7, 5};
    int n = 6;
    int second_smallest = secondSmallest(arr, 6);
    int second_largest = secondLargest(arr, 6);
    cout << "Second Largest Element is " << second_largest << endl;
    cout << "Second Smallest Element is " << second_smallest << endl;
    return 0;
}