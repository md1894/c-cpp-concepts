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
        void fun(int a){
            cout << "Called void derived::fun(int a)" << endl;
        }
};

int main(){
    derived d;
    cout << "Compiled Successfully " << endl;
    return 0;
}