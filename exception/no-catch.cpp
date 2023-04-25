#include <iostream>
using namespace std;

int main()
{
	try {
	throw 'a';
	}
	catch (int x) {
		cout << "Caught ";
	}
	return 0;
}

/*
no matching catch block
program abnormally terminates

output:-->

terminate called after throwing an instance of 'char'
Aborted (core dumped)
*/
