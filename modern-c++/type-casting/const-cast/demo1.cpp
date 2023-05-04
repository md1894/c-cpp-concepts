#include<iostream>
using namespace std;

void fun(int *a){
    
}

int main(){
    int a = 12;
    const int *ptr = &a;
    //fun(ptr);//error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
    int *ptr1 = const_cast<int*>(ptr);
    fun(ptr1); //OK
    return 0;
}