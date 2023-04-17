#include<iostream>
using namespace std;

class info;



class utility{
    public:
        void display(info &i);
};

class info{
    private:
        int private_member;
    protected:
        int protected_member;
    public:
        info(){
            this->private_member = 125;
            this->protected_member = 225;
        }

    friend void utility::display(info &i);
};

void utility::display(info &i){
    cout << "Value of Private member is " << i.private_member << endl;
    cout << "Value of protected member is " << i.protected_member << endl;
}



int main(){
    utility u;
    info i;
    u.display(i);
    return 0;
}

/*
output:

Value of Private member is 125
Value of protected member is 225

*/

