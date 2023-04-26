#include<iostream>
using namespace std;

class base{
    public:
        virtual void fun(){
            cout << "Called void base::fun() " << endl;
        }
};

class derived : public base{
    public:
    /*
    In short, it serves the following functions. It helps to check if: 

    There is a method with the same name in the parent class.
    The method in the parent class is declared as “virtual” which means it was intended to be rewritten.
    The method in the parent class has the same signature as the method in the subclass.
    */
        void fun(int a) override {
            cout << "Called void derived::fun(int a)" << endl;
        }
};

int main(){
    derived d;
    /*
    compilation error
    */
    return 0;
}