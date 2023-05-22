#include <iostream>

// Function that takes a callback lambda function as a parameter
void performOperation(int x, int y, void(*callback)(int)) {
    int result = x + y;

    // Invoke the callback function
    callback(result);
}

int main() {
    int a = 5;
    int b = 3;
    int z = 500;

    // Pass a lambda function as a callback to performOperation function
    performOperation(a, b, [](int result) {
        std::cout << "The result is: " << result << std::endl;
    });

    return 0;
}
