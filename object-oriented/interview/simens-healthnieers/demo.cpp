#include<iostream>
using namespace std;

class base{
    int a;
    string name;

    public:
        base(int a, string name):a(a), name(name){
            cout << "base constructor called " << endl;
        }

        void display(){
            cout << "a = " << this->a << " name is " << this->name << endl;
        }

        virtual void run(){
            cout << "base class run method " << endl;
        }
};

class derived : public base{
    public:
        derived(int a, string name):base(a, name){
            cout << "derived constructor called " << endl;
        }

        void run(){
            cout << "derived class run method " << endl;
        }

        void run(int a = 10, int b = 10){
            cout << "run(int a = 10, int b = 10) method called in derived class " << endl;
        }

        void display(){
            cout << "inside display method " << endl;
            base::display();
        }
};

int main(){
    base *b = new derived(10, "mehul");
    b->run();
    
    //b->run(10);
    /*
    error: no matching function for call to ‘base::run(int)’
    45 |     b->run(10);
    */

    ((derived*)b)->run(10);
    
    //((derived*)b)->run();
    /*
        error: call of overloaded ‘run()’ is ambiguous
        46 |     ((derived*)b)->run();
            |     ~~~~~~~~~~~~~~~~~~^~
        demo.cpp:28:14: note: candidate: ‘virtual void derived::run()’
        28 |         void run(){
            |              ^~~
        demo.cpp:32:14: note: candidate: ‘void derived::run(int, int)’
        32 |         void run(int a = 10, int b = 10){
    */
    b->display();
    delete b;
    return 0;
}

/*
output :: 

base constructor called 
derived constructor called 
derived class run method 
run(int a = 10, int b = 10) method called in derived class 
a = 10 name is mehul
*/