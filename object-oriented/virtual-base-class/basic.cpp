#include<iostream>
using namespace std;

class A{
    public:
    
    void show() {
        cout << "Hello form A \n";
    }
};

class B : public A{

};

class C : public A{
};

class D : public B, public C{

};

/*
As we can see from the figure that data members/function of class A are inherited twice 
to class D. One through class B and second through class C.
When any data / function member of class A is accessed by an object of class D,
ambiguity arises as to which data/function member would be called?
One inherited through B or the other inherited through C.
This confuses compiler and it displays error.
 
*/

int main(){
    D d;
    d.show(); /// compiler is confused
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