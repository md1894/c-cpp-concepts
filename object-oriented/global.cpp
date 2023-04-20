#include<iostream>
using namespace std;


int a = 10;

int main(){
    int a = 5;
    cout << "Global Variable a = " << ::a << endl;
    cout << "Local Variable a = " << a << endl;
    return 0;
}