#include<iostream>
using namespace std;


// only one single object got created
class singleton{
    static singleton *instance_address;

    // to prevent object instantiation 
    singleton(){
        cout << "instance created " << endl;
    }

    public:
        static singleton *get_instance(){
            if(singleton::instance_address == nullptr){
                singleton::instance_address = new singleton();
            }
            return singleton::instance_address;
        }

        ~singleton(){
            if(singleton::instance_address){
                delete singleton::instance_address;
                singleton::instance_address = nullptr;
            }
        }
};

singleton *singleton::instance_address = nullptr;

int main(){
    // singleton* ptr = new singleton();
    singleton *ptr1 = singleton::get_instance();
    cout << "Address is " << ptr1 << endl;
    singleton *ptr2 = singleton::get_instance();
    cout << "Address is " << ptr2 << endl;
    return 0;
}

/*
instance created 
Address is 0x5640b1179eb0
Address is 0x5640b1179eb0
*/