#include<iostream>
using namespace std;

class parent1 {
    public:
        parent1(){
            cout << "parent1 constructor" << endl;
        }

        ~parent1(){
            cout << "parent1 destructor" << endl;
        }
};

class parent2{
    public:
        parent2(){
            cout << "parent2 constructor" << endl;
        }

        ~parent2(){
            cout << "parent2 destructor" << endl;
        }
};

class child : public parent2, parent1 {
    public:
        child(){
            cout << "child constructor" << endl;
        }

        ~child(){
            cout << "child destructor" << endl;
        }
};


int main(){
    child c;
    return 0;
}

/*
parent2 constructor
parent1 constructor
child constructor
child destructor
parent1 destructor
parent2 destructor
*/