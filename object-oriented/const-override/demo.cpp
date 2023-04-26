#include<iostream>
using namespace std;

class demo{
    int a;
    int b;

    public:
        demo(int a, int b){
            this->a = a;
            this->b = b;
        }

        void display_const() const {
            cout << "This Function can only be invoked by a constant object " << endl;
            //this->a += 55; // this is a compile time error
            /*
            demo.cpp: In member function ‘void demo::display_const() const’:
            demo.cpp:16:21: error: assignment of member ‘demo::a’ in read-only object
            16 |             this->a += 55;
            */
        }

        void display(){
            cout << "This function is a normal display function " << endl;
            this->a += 55; // this is completely ok
            // here we are modifying the value of a member variable
        }
};

/*
normal object can call any method
const and non-const method
*/
int main(){
    demo d(10, 5);
    d.display_const();// OK
    d.display();// OK
    
    const demo c_demo(10, 58);
   // c_demo.display(); // compile time error
   // using a constant object you can call only const functions
   c_demo.display_const();
    return 0;
}