#include<iostream>
using namespace std;

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
    
    friend class display;

};

class display{
    public:
        void display_data(info &i){
            cout << "class display is now accessing private and protected members "
                <<endl << "of class info, because display is friend class of info" << endl;
            cout << "Value of private_member is " << i.private_member << endl;
            cout << "Value of protected member is " << i.protected_member << endl;
        }
};

int main(){
    info i;
    display d;
    d.display_data(i);
    return 0;
}

/*
output :

class display is now accessing private and protected members 
of class info, because display is friend class of info
Value of private_member is 125
Value of protected member is 225

*/

/*
explanation
class display is declared as a friend class inside class info
that is why display class have access of private,protected members of class info
*/