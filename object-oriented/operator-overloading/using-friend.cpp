#include<iostream>
using namespace std;

class complex;



class complex{
    int real;
    int imaginary;

    public:
        complex(){
            this->real = 0;
            this->imaginary = 0;
        }

        complex(int real, int imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }

        void display(){
            cout << "Real Part : " << this->real << " Imaginary Part " << this->imaginary << endl;
        }

        friend complex operator+(complex &c1, complex &c2);
};

complex operator+(complex &c1, complex &c2){
    complex a;
    a.real = c2.real + c1.real;
    a.imaginary = c2.imaginary + c1.imaginary;
    return a;
}

int main(){
    complex c1(2, -5);
    complex c2(5, 4);
    complex c3 = c1 + c2;
    c3.display();
    return 0;
}