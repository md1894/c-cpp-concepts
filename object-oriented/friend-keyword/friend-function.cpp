#include<iostream>
using namespace std;

/*
program to demonstrate global friend function
*/

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

        friend void display(info &i);
};


/*
as function display is declared as a friend function of class info
it has access of its private,protected members
*/
void display(info &t){
    cout << "Value of private_member is " << t.private_member << endl;
    cout << "Value of protected_member is " << t.protected_member << endl;
}

int main(){
    info i;
    display(i);
    return 0;
}

/*
Value of private_member is 125
Value of protected_member is 225
*/
