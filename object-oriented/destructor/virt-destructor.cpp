#include<iostream>
using namespace std;

class base{

    public:
        virtual ~base(){
            cout << "Base Destroyed "<< endl;
        }
};

class derived : public base{
    public:
        ~derived(){
            cout << "Derived Destroyed " << endl;
        }
};

int main(){
    derived *d = new derived;
    base *b = d;
    delete b;
    return 0;
}

/*

correct expected output

Derived Destroyed 
Base Destroyed
*/