/*
In C++, `std::future` and `std::promise` 
are components of the C++ Standard Library 
that facilitate asynchronous programming 
and inter-thread communication. 
They are part of the futures and promises mechanism, 
which allows one thread to provide a value 
or an exception to another thread, 
which can then retrieve the value 
or handle the exception at a later point.



In the above code, we create a `std::promise<int>` 
object called `promise`. 
We then obtain a `std::future<int>` object 
from the promise using the `get_future()` function. 
The future is associated with the promise 
and allows us to retrieve the value 
that will be set in the promise.

We create a separate thread using `std::thread` 
that performs a calculation (in this case, the sum of two numbers) 
and sets the result in the promise using `set_value()`. 
Meanwhile, in the main thread, we call `future.get()` to wait 
for the result and retrieve it. 
The `get()` function blocks until 
the value is available in the future.

Once we have the result, 
we can use it as needed. 
In this example, we simply print it out. 
Finally, we join the thread to ensure 
it completes before the program exits.

Promises and futures allow for more complex 
communication patterns between threads, 
such as one thread providing a result to 
multiple threads, or multiple threads providing results to a single thread. 
They provide a powerful mechanism for 
asynchronous programming and coordination between threads.

Note that error handling, 
exception propagation, and other features related 
to futures and promises have not been covered 
in this simple example. 
In practice, it is important to handle 
exceptions and errors properly when 
working with futures and promises.
*/

#include <iostream>
#include <future>
#include<unistd.h>

int calculateSum(int a, int b)
{
    sleep (5);
    return a + b;
}

int main()
{
    std::promise<int> promise;  // Create a promise
    std::future<int> future = promise.get_future();  // Get the future associated with the promise

    std::thread thread([&promise]() {
        int result = calculateSum(10, 20);
        promise.set_value(result);  // Set the value in the promise
    });

    // Wait for the result and retrieve it from the future
    int result = future.get();

    std::cout << "Sum: " << result << std::endl;

    thread.join();

    return 0;
}

/*
Sum: 30
*/
