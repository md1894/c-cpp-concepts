#include<iostream>
using namespace std;

class demo{
    public:
        int member_a;
        int member_b;
    private:
        demo(int a, int b){
            this->member_a = a;
            this->member_b = b;
        }
    public:
        demo(){
            this->member_a = 0;
            this->member_b = 0;
        }
};

int main(){
    /// constructor must be public
    demo d;
    return 0;
}