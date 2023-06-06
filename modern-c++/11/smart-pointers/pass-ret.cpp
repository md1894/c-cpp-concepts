#include <iostream>
#include <memory>

// Function that takes a smart pointer as a parameter
void processSmartPtr(std::unique_ptr<int> ptr) {
    std::cout << "Value inside processSmartPtr: " << *ptr << std::endl;
    // You can perform operations on the object pointed to by the smart pointer
    *ptr *= 2;
}

// Function that returns a smart pointer
std::unique_ptr<int> createSmartPtr() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    return ptr;
}

int main() {
    // Passing a smart pointer to a function
    std::unique_ptr<int> myPtr = std::make_unique<int>(10);
    processSmartPtr(std::move(myPtr));  // Using std::move to transfer ownership

    // Returning a smart pointer from a function
    std::unique_ptr<int> returnedPtr = createSmartPtr();
    std::cout << "Value inside returnedPtr: " << *returnedPtr << std::endl;

    return 0;
}

