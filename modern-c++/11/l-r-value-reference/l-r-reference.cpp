#include<iostream>
using namespace std;

/*
generally value which is of left-side of '=' operator is the l-value
value which is of right-side of '=' operator is r-value
*/

int fun(){
    return 100 + 5%2;
}

void fun(int &a){
    cout << "Inside Function void fun(int &a) accepts l-value ref" << endl;  
}

// note that r-value reference is denoted by && sign
void fun1(int &&a){
    cout << "Inside Function void fun(int &&a) accepts r-value ref" << endl;  
}


int main(){
    /*
    a is the l-value reference and 10 is the r-value reference
    */
    int a = 10;

    /*
    here a is the r-value reference and a_ref is the l-value reference
    */
    int &a_ref = a;

    /*
    here b is the l-value reference and expression is the r-value reference
    */
    int b = fun() + 5 + a;

    //error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
    //fun1(a);

    fun1(fun() + 5 + a);// OK OUTPUT
    //Inside Function void fun(int &&a) accepts r-value ref

    //cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    // fun(10); // compilation error
    return 0;
}