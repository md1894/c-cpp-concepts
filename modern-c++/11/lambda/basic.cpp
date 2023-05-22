#include <iostream>

int main() {
    int x = 5;
    int y = 3;

    // Lambda expression that captures x by value and y by reference
    auto sum = [x, &y]() -> int {
        return x + y;
    };

    std::cout << sum() << std::endl;  // Output: 8

    return 0;
}
