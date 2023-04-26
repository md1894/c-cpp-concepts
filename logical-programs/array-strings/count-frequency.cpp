/*
Example 1:
Input: arr[] = {10,5,10,15,10,5};
Output: 10  3
        5  2
        15  1
        Explanation: 10 occurs 3 times in the array
        5 occurs 2 times in the array
        15 occurs 1 time in the array

Example2: 
Input: arr[] = {2,2,3,4,4,2};
Output: 2  3
        3  1
        4  2
        Explanation: 2 occurs 3 times in the array
        3 occurs 1 time in the array
        4 occurs 2 time in the array
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void countOccurancesSimple(int *array, int n){
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(visited[i])
            continue;
        int count = 1;
        for(int j = i+1; j < n; j++){
            if(array[i] == array[j]){
                count++;
                visited[j] = true;
            }
        }
        cout << "Occurance of " << array[i] << " " << "is " << count << endl;
    }
}

void countOccuranceBest(int *array, int n){
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[array[i]]++; /// Takes O(1) time complexity
    }

    for(auto m : freq){
        cout << "Occurance of " << m.first << " is " << m.second << endl;
    }
}

int main(){
    int arr[] = {10,5,10,15,10,5};
    int n = 6;
    countOccurancesSimple(arr, n);
    countOccuranceBest(arr, n);
    return 0;
}