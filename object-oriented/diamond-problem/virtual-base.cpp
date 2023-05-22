#include <iostream>
using namespace std;

class A
{
public:
    void fun()
    {
        cout << "A::fun" << endl;
    }
};

class B : public virtual A
{
public:
    void fun()
    {
        cout << "B::fun" << endl;
    }
};

class C : public virtual A
{
public:
    void fun()
    {
        cout << "C::fun" << endl;
    }
};

class D : public B, public C
{
public:
    
};

int main()
{
    D d;
    d.fun();
}