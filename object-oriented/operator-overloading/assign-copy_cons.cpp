/*
just observe that when a copy constructor gets called 
and when copy constructor called

difference between copy constructor and assignment operator

CC: when new object is to be constructed
 =: when you have to copy fields of one object into another existing object

CC: New memory gets allocated
 =: No new memory gets allocated

compiler provides default copy constructor and default overloaded assignment operator

*/


#include <iostream>
using namespace std;

class demo{
    int *ptr;
    
    public:
        demo(){
            this->ptr = new int(0);
            cout << "Default Constructor called " << endl;
        }
        
        demo(const demo &d){
            this->ptr = new int;
            if(this->ptr != nullptr){
                *(this->ptr) = *(d.ptr);
            }
            cout << "copy constructor called " << endl;
        }
        
        demo& operator=(const demo &d){
            *(this->ptr) = *(d.ptr);
            cout << "custom assignment operator called " << endl;
            return *this;
        }
        
        void display(){
            cout << "value of ptr is " << *(this->ptr) << endl;
        }
        
        void set(int a){
            *(this->ptr) = a;
        }
        
        ~demo(){
            if(this->ptr){
                delete this->ptr;
                this->ptr = nullptr;
            }
        }
};

// Driver Code
int main()
{
    demo d;
    d.set(155);
    demo d2(d);
    demo d3 = d;
    demo d4;
    d4 = d;
	return 0;
}

/*
output :

Default Constructor called 
copy constructor called 
copy constructor called 
Default Constructor called 
custom assignment operator called 

*/
