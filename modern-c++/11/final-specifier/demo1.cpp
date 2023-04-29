#include<iostream>
using namespace std;

class base{
    public:
        virtual void fun () final {

        }
};

class derived : public base{
    public:
        void fun() {

        }
};


// compilation error
int main(){

    return 0;
}

/*
demo1.cpp:13:14: error: virtual function ‘virtual void derived::fun()’ overriding final function
   13 |         void fun() {
*/