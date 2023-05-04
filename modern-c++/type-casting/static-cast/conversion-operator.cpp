#include<iostream>
#include<cmath>
using namespace std;

/*
Sometimes, it is required to convert one concrete type to another concrete type or primitive type 
implicitly. Conversion operators play an important role in such situations. 
It is similar to the operator overloading function in class.
*/

class complex{
    double real;
    double imaginary;

    public:
        complex(double real, double imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }

        double mag(){
            return get_mag();
        }

        operator double(){
            cout << "Conversion Operator gets called " << endl;
            return get_mag();
        }
    private:
        double get_mag(){
            return sqrt(real*real + imaginary*imaginary);
        }
};

int main(){
    complex c(3.0, 4.0);
    cout << c.mag() << endl;
    cout << c <<endl;
    return 0;
}

/*
5
Conversion Operator gets called 
5
*/