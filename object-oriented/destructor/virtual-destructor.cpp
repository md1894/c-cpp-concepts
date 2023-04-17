/*
Deleting a derived class object using a pointer of base class type 
that has a non-virtual destructor results in undefined behavior.
To correct this situation, 
the base class should be defined with a virtual destructor. 
*/

#include<iostream>
using namespace std;

class base{
    public:
        ~base(){
            cout << "Base destroy" << endl;
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
here you can see that only base object is destroyed 
*/

/*

output -->

Base destroy
*/