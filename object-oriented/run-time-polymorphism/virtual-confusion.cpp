/*
virtual function will have its effect
in case of inheritance and function over-riding
*/

#include<iostream>
using namespace std;

class A {
	public:
		virtual void fun1() {
			cout << "A::fun1" << endl;
		}

		void fun2() {
			cout << "A::fun2" << endl;
		}
};

class B : public A {
	public:
		void fun1 () {
			cout << "B::fun1" << endl;
		}

		virtual void fun2() {
			cout << "B::fun2" << endl;
		}
};

class C : public B {
	public:
		void fun2 (){
			cout << "C::fun2" << endl;
		}
};

class D : public A {
	public:
		void fun2() {
			cout << "D::fun2" << endl;
		}
};

int main() {
	A *ptr = new B ();
	ptr->fun1();
	ptr->fun2();// there is no effect of virtual keyword
	
	B *ptr1 = new C ();
	ptr1->fun2(); // now there is effect of virtual keyword

	A *ptr2 = new D ();
	ptr2->fun2();
	return 0;
}

/*
 * fun2 is declared as virtual , 
 * but still Base version of fun2 is called
 * what compiler does , as per pointer type (A*)
 * it checks function `fun2` in class A
 * in class A it is a normal function
 * that is why compiler does early binding to that function
 * this is the reason instead of B::fun2
 * A::fun2 is called
 * */


// output

/*
B::fun1
A::fun2
C::fun2
*/
