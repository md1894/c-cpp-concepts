#include<iostream>
using namespace std;

class A{
    protected:
    static int a;
    public:
    
    static void display(){
        cout << "Value of a inside void A::display() is " << a << endl;
    }
};

int A::a = 25;

/*
static data members and functions are not inherited by derived class
but inside derived class it is accessible
*/
class B : public A{
    public:
        void display(){
            ++a;
            A::display();
        }
};

int main(){
    B b;
    b.display();
    return 0;
}