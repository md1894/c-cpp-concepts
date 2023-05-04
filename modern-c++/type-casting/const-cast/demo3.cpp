#include<iostream>
using namespace std;

int main(){
    char c = 'C';
    char *ptr = &c;
    int *ptr1 = (int*)&c; // this does not give any compilation error in c-style casting
    //gives compilation error
    //int *ptr2 = const_cast<int*> (&c); //error: invalid ‘const_cast’ from type ‘char*’ to type ‘int*’
    return 0;
}