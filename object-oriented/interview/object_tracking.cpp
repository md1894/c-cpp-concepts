#include <iostream>

class Object {
public:
    static int count_with_new;
    static int count_without_new;

    Object() {
        count_without_new++;
    }

    static void* operator new(size_t size) {
        count_with_new++;
        return ::operator new(size);
    }

    static void operator delete(void* ptr) noexcept {
        count_with_new--;
        ::operator delete(ptr);
    }
};

int Object::count_with_new = 0;
int Object::count_without_new = 0;

int main() {
    // Create objects using new operator
    Object* obj1 = new Object();
    Object* obj2 = new Object();

    // Create objects without new operator
    Object obj3;
    Object obj4;

    // Print the counts
    std::cout << "Objects created using new operator: " << Object::count_with_new << std::endl;
    std::cout << "Objects created without new operator: " << Object::count_without_new << std::endl;

    // Clean up memory
    delete obj1;
    delete obj2;

    return 0;
}

/*
In the given code, the lines:

	return ::operator new(size);
	::operator delete(ptr);

	perform memory allocation and deallocation operations using the global operator new and operator delete functions respectively.

    	return ::operator new(size);

	The return statement here is used to return the memory address of the allocated memory block. 
	::operator new(size) is a global function that allocates a block of memory of the specified size in bytes. 
	The :: scope resolution operator is used to explicitly specify that we want to use the global version of 
	operator new instead of any overloaded version.

    	::operator delete(ptr);

	The ::operator delete is a global function that deallocates a block of memory pointed to by ptr. 
	This function is responsible for freeing the memory previously allocated by ::operator new or any other custom allocator. 
	Again, the :: scope resolution operator is used to specify the global version of operator delete instead of any overloaded version.

	By using these global memory allocation and deallocation functions, 
	the code keeps track of the count of objects created using the new operator 
	and appropriately increments or decrements the counts when memory is allocated or deallocated.

*/
