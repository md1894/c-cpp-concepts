#include<iostream>
#include<string.h>
using namespace std;

bool check_palindrome(char str[]){
    int low = 0;
    int high = strlen(str) - 1;
    while(low < high){
        if(str[low] != str[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int main(){
    char str[]{"abba"};
    cout << check_palindrome(str) << endl;
    return 0;
}