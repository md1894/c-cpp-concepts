#include<iostream>
using namespace std;

class info{
    int *a;

    public:
        info(){
            a = nullptr;
        }

        info(int a){
            this->a = new int(a);
        }

        void display(){
            cout << "value of a is " << *a << " Address is "<< a <<endl;
        }

        void set_value(int v){
            *(this->a) = v;
        }

        ~info(){
            if(this->a)
                delete this->a;
        }
};

int main(){
    info i(10);
    info a = i;
    i.display();
    a.display();
    i.set_value(20);
    i.display();
    a.display();
    return 0;
}

/*

output -->

value of a is 10 Address is 0x56130b897eb0
value of a is 10 Address is 0x56130b897eb0
value of a is 20 Address is 0x56130b897eb0
value of a is 20 Address is 0x56130b897eb0

free(): double free detected in tcache 2
Aborted (core dumped)


as both pointers point to a same memory location
free function is called on same memory location 
2 times

*/