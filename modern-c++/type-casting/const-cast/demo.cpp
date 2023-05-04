#include<iostream>
using namespace std;

/*
const_cast is used to remove the 
const and volatile qualifier of the variable
*/

class demo{
    int a;
    public:
    demo(int a){
        this->a = a;
    }

    // using const_cast we can change data inside const function
    void fun() const{
        //this->a += 15;//error: assignment of member ‘demo::a’ in read-only object
        (const_cast<demo*> (this))->a += 15; // OK
    }

    void display(){
        cout << "Value of a is " << this->a << endl;
    }
};

int main(){
    demo d(15);
    d.fun();
    d.display();
    return 0;
}

/*
Value of a is 30
*/