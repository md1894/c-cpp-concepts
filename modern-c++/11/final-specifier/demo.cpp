/*
In Java, we can use final for a function to make sure that it cannot be overridden. 
We can also use final in Java to make sure that a class cannot be inherited. 
Similarly, the latest C++ standard C++ 11 added final. 
Use of final specifier in C++ 11: 

Sometimes you don’t want to allow derived class to override the base class’ virtual function. 
C++ 11 allows built-in facility to prevent overriding of virtual function using final specifier. 

Consider the following example which shows use of final specifier. This program fails in compilation. 
*/

#include<iostream>
using namespace std;

class base final {

};

class derived : public base{

};

// compilation fails
int main(){

    return 0;
}

/*
demo.cpp:20:7: error: cannot derive from ‘final’ base ‘base’ in derived type ‘derived’
   20 | class derived : public base{
*/