#include<iostream>
using namespace std;


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

        complex operator+(complex &c){
            complex a;
            a.real = this->real + c.real;
            a.imaginary = this->imaginary + c.imaginary;
            return a;
        }
};

int main(){
    complex c1(2, -5);
    complex c2(5, 4);
    complex c3 = c1 + c2;
    c3.display();
    return 0;
}