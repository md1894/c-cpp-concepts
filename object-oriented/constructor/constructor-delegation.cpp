/*
Constructor delegation in C++ is a feature that allows 
a constructor to call another constructor of the same class 
to perform initialization tasks. 
It helps avoid code duplication and promotes code reuse. 
The delegation is achieved using the constructor initializer list.

Here's an example to demonstrate 
constructor delegation in C++:

```cpp
#include <iostream>

class MyClass {
private:
    int value1;
    int value2;

public:
    // Constructor with two parameters
    MyClass(int val1, int val2) : value1(val1), value2(val2) {
        std::cout << "Constructor with two parameters called." << std::endl;
    }

    // Constructor with one parameter (delegating constructor)
    MyClass(int val) : MyClass(val, 0) {
        std::cout << "Constructor with one parameter called." << std::endl;
    }

    void PrintValues() {
        std::cout << "value1: " << value1 << ", value2: " << value2 << std::endl;
    }
};

int main() {
    MyClass obj1(10); // Calls the constructor with one parameter
    obj1.PrintValues();

    MyClass obj2(20, 30); // Calls the constructor with two parameters
    obj2.PrintValues();

    return 0;
}
```

In the above code, the class `MyClass` has two constructors: 
one that takes two parameters and another 
that takes a single parameter. 
The constructor with a single parameter delegates 
the initialization tasks to the constructor with two parameters by using 
`: MyClass(val, 0)` in the constructor initializer list. 
This way, the constructor with one parameter calls the constructor with two parameters, 
reusing its functionality.

When we run the code, the output will be:

```
Constructor with two parameters called.
Constructor with one parameter called.
value1: 10, value2: 0
Constructor with two parameters called.
value1: 20, value2: 30
```

As we can see, the constructor with one parameter delegates 
the initialization to the constructor with two parameters, 
and both constructors are invoked correctly.
*/

#include<iostream>
using namespace std;

class person {
    string name;
    string age;
    string gender;
    string address;

    public:
        person():person("NF", "NF", "NF", "NF"){
            cout << "person() called" << endl;
        }
        person(string name):person(name, "NF", "NF", "NF") {
            cout << "person(name) called" <<endl;
        }

        person(string name, string age) : person(name, age, "NF", "NF") {
            cout << "person(name, age) called" << endl;
        }
        person(string name, string age, string gender) : person(name, age, gender, "NF") {
            cout << "person(name, age, gender) called" << endl;
        }

        /*
        #include <iostream>

        class MyClass {
            private:
            
            int value1;
            int value2;

            public:

            // Constructor with initializer list
            MyClass(int val1, int val2) : value1(val1), value2(val2) {
            // Constructor body
            }
        };

        */
        person(string namel, string agel, string genderl, string addressl) : 
            name(namel), age(agel), gender(genderl), address(addressl)
        {
            cout << "person(name, age, gender, address) called" << endl;    
        }

        friend ostream& operator<<(ostream &o, const person &p) {
            o << p.name + " : " + p.age + " : " + p.gender + " : " + p.address << endl; 
            return o;
        }
};

int main(){
    person p;
    cout << p;
    person p1("mehul");
    cout << p1;
    person p2("mehul", "29");
    cout << p2;
    person p3("mehul", "29", "male");
    cout << p3;
    person p4("mehul", "29", "male", "pune");
    cout << p4;
    return 0;
}

/*
person(name, age, gender, address) called
person() called
NF : NF : NF : NF
person(name, age, gender, address) called
person(name) called
mehul : NF : NF : NF
person(name, age, gender, address) called
person(name, age) called
mehul : 29 : NF : NF
person(name, age, gender, address) called
person(name, age, gender) called
mehul : 29 : male : NF
person(name, age, gender, address) called
mehul : 29 : male : pune
*/