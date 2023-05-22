#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Lambda expression that squares each element of the vector
    std::for_each(numbers.begin(), numbers.end(), [](int& num) {
        num = num * num;
    });

    // Output the modified vector
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
