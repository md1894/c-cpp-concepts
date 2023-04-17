#include<iostream>
using namespace std;


class complex{
    double real;
    double imaginary;

    public:
        explicit complex(double real = 0.0, double imaginary = 0.0){
            this->imaginary = imaginary;
            this->real = real;
        }

        bool operator==(complex c){
            return this->real == c.real && this->imaginary == c.imaginary;
        }
};

int main(){
    complex c(3.0, 0.0);
    if(c == 3.0){
        cout << "Same values" << endl;
    }else{
        cout << "different values" << endl;
    }
    return 0;
}

/*

produces error , because of keyword explicit

explicit1.cpp:22:10: error: no match for ‘operator==’ (operand types are ‘complex’ and ‘double’)
   22 |     if(c == 3.0){
      |        ~ ^~ ~~~
      |        |    |
      |        |    double
      |        complex

*/