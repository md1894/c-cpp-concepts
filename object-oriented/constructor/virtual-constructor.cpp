#include<iostream>
using namespace std;

class Base {
    public:
        static Base* virtual_constructor(int type);

        Base() {}

        virtual void action() = 0;

        virtual ~Base(){}
};

class Derived : public Base {
    public:
        void action () {
            cout << "Inside Derived::action() method " << endl;
        }
};

class Derived1 : public Base {
    public:
        void action () {
            cout << "Inside Derived1::action() method " << endl;
        }
};


class Derived2 : public Base {
    public:
        void action () {
            cout << "Inside Derived2::action() method " << endl;
        }
};


/*
in C++ we dont have virtual destructor
but with defination of factory method
we can acheive that feature
*/
Base* Base::virtual_constructor(int type) {
    if(type == 1) {
        return new Derived();
    }else if(type == 2) {
        return new Derived1();
    }else if(type == 3) {
        return new Derived2();
    }else
        return nullptr;
}

int main() {
    Base* ptr = Base::virtual_constructor(1);
    ptr->action();
    Base* ptr1 = Base::virtual_constructor(2);
    ptr1->action();
    Base* ptr2 = Base::virtual_constructor(3);
    ptr2->action();
    delete ptr;
    delete ptr1;
    delete ptr2;
    return 0;
}


/*
Inside Derived::action() method 
Inside Derived1::action() method 
Inside Derived2::action() method
*/