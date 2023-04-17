#include<iostream>
using namespace std;


class rectangle{
    private:
        int *width;
        int *breadth;
    public:
        rectangle(){
            this->breadth = NULL;
            this->width = NULL;
        }
        
        rectangle(int w, int b){
            this->width = new int;
            *(this->width) = w;
            this->breadth = new int;
            *(this->breadth) = b;
        }

        /*
        proper deep copy is done inside this
        user defined copy constructor
        */ 
        rectangle(rectangle &r){
            this->width = new int;
            *(this->width) = *(r.width);
            this->breadth = new int;
            *(this->breadth) = *(r.breadth);
        }

        ~rectangle(){
            if(this->width){
                delete this->width;
                this->width = nullptr;
            }
            if(this->breadth){
                delete this->breadth;
                this->breadth = nullptr;
            }
        
        }

        void display(){
            cout << "Width " << *(this->width) << " Breadth " << *(this->breadth) << endl;
            cout << "Address of Width : " << this->width << " Address of breadth : " << this->breadth << endl;
        }
};

int main(){
    rectangle r = rectangle(10, 20);
    rectangle r1 = r;
    r.display();
    r1.display();
    return 0;
}
