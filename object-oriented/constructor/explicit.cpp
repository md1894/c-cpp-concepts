#include<iostream>
using namespace std;


class complex{
    double real;
    double imaginary;

    public:
        complex(double real = 0.0, double imaginary = 0.0){
            this->imaginary = imaginary;
            this->real = real;
        }

        bool operator==(complex c){
            return this->real == c.real && this->imaginary == c.imaginary;
        }
};

int main(){
    complex c(3.0, 0.0);
    /*
        implicitly 3.0 is converted to object of class complex
        because of its constructor
        this 3.0 is compared with object of type complex
        and compiler tries to match its type

        to avoid this you can use explicit keyword with constructor
        that takes only one argument
    */
    if(c == 3.0){
        cout << "Same values" << endl;
    }else{
        cout << "different values" << endl;
    }
    return 0;
}

/*

output -->

Same values
*/