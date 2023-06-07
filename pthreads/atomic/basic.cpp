/*
In C++, atomic variables are a special type of variable 
that provide atomic operations on their values. 
These operations ensure that the variable is accessed 
and modified atomically, meaning that they are performed 
as a single, indivisible operation. 
This guarantees that the variable's value 
is not affected by concurrent or 
simultaneous accesses from multiple threads.

Atomic variables are typically used in multi-threaded 
programs where multiple threads may access 
and modify the same variable concurrently. 
Without atomic operations, concurrent access 
to a variable could lead to race conditions 
and undefined behavior.


In the below code, we define an atomic variable called `counter` 
using the `std::atomic<int>` template. 
We then create two threads that concurrently 
increment the `counter` by 100,000. 
Since the `counter++` operation is atomic, 
we don't have to worry about race conditions.

After both threads complete, 
we output the final value of the `counter`. 
In this example, the output should be `200000` 
because each thread performs 100,000 increments.

Atomic variables provide various atomic operations, 
such as increment, decrement, compare-and-swap, 
load, store, etc. 
These operations ensure that the variable is 
accessed and modified atomically. 
You can refer to the C++ documentation for 
more details on the available atomic operations and their usage.

Note: It's important to use atomic variables only when necessary. 
In many cases, synchronization mechanisms like mutexes or locks 
might be more appropriate and efficient. 
Atomic variables are generally used for simple cases 
where fine-grained synchronization is required.
*/



#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0);  // Atomic variable

// int counter = 0; // without atomic variable

void incrementCounter()
{
    for (int i = 0; i < 100000; ++i) {
        counter++;  // Atomic increment operation
    }
}

int main()
{
    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    thread1.join();
    thread2.join();

    std::cout << "Counter value: " << counter << std::endl;

    return 0;
}

/*
output with atomic variable

Counter value: 200000

*/

/*

output without atomic variable 

Counter value: 111132

*/