#include<iostream>
using namespace std;

/*
A pure virtual function is implemented by classes which are derived from a Abstract class. 
Following is a simple example to demonstrate the same.
*/

class base{
    /*private:
    virtual void fun() = 0;*/
    public:
        virtual void fun() = 0;
        void fun1();
};

void base::fun1(){
    cout << "base::fun1() called " << endl;
}

class derived : public base{
    public:
        void fun();
};

void derived::fun(){
    cout << "derived::fun() called" << endl;
}

int main(){
    derived d;
    /*
    base b; /// cannot create object of a abstract class
    error: cannot declare variable ‘b’ to be of abstract type ‘base’
   32 |     base b;

    */
    d.fun();
    return 0;
}