In C++11, the lambda feature was introduced as a way to define anonymous functions or 
function objects inline. Lambdas provide a concise and flexible syntax for creating small, 
local functions without the need for explicit function declarations.

The basic syntax for a lambda expression is as follows:

```
[capture-list](parameters) -> return-type {
    // Function body
}
```

Let's break down the different components:

1. Capture list: This optional part allows you to specify which variables from the enclosing scope 
should be captured by the lambda. You can capture variables by value (`[x]`) 
or by reference (`[&x]`). 
The capture list can also be empty (`[]`) 
if you don't need to capture any variables.

2. Parameters: This is similar to the parameter list in regular function declarations. 
You can specify the input parameters for the lambda function.

3. Return type: This is an optional part that specifies the return type of the lambda function. 
If omitted, the return type is deduced automatically based on the return statements 
inside the function body.

4. Function body: This is the actual code 
that defines the behavior of the lambda function.

Here's an example to illustrate the usage of lambdas:

```cpp
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
```

In the example, we define a lambda expression named `sum` that captures `x` by value and `y` by reference. 
The lambda takes no parameters and returns the sum of `x` and `y`.
We then call the lambda function `sum()` and print the result, which is 8.

Lambdas are particularly useful in scenarios where you need to pass a small piece of code 
as an argument to another function, such as in algorithms like `std::for_each` 
or when working with containers like `std::vector`.