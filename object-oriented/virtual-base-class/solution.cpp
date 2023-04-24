#include<iostream>
using namespace std;

class A{
    public:
    
    void show() {
        cout << "Hello form A \n";
    }
};

class B : public virtual A{

};

class C : virtual public A{
};

class D : public B, public C{

};

/*
as we are inheriting derived classes using virtual base class
compiler will make sure that only one copy will get inherited
 
*/

int main(){
    D d;
    d.show(); /// compiler is not confused
    return 0;
}

/*

compilation error : 

basic.cpp: In function ‘int main()’:
basic.cpp:25:7: error: request for member ‘show’ is ambiguous
   25 |     d.show();
      |       ^~~~
basic.cpp:7:10: note: candidates are: ‘void A::show()’
    7 |     void show() {
      |          ^~~~
basic.cpp:7:10: note:                 ‘void A::show()’

*/