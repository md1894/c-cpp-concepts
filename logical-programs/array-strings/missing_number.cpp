/*
find missing number in an unsorted array from 1 to n

n = 5
arr = {1, 5, 2, 3}

ans : 4

missing number is 4

*/

#include<iostream>
using namespace std;

int main(){
    int a[4] = {1,5,2,3};
    int n = 5;
    int sum = 1;

    for(int i = 2; i < n+1  ; i++){
        sum += i;
        sum -= a[i-2];
        
    }

    cout << "Missing Number is " << sum << endl;

    return 0;
}