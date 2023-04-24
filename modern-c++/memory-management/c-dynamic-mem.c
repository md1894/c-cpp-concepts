#include<stdio.h>
#include<stdlib.h>

/*


In C, `malloc()` and `calloc()` are two functions that are used to allocate memory dynamically 
at runtime. However, they have some differences in the way they allocate and initialize memory:

1. Syntax:
   - `void *malloc(size_t size)` - allocates a block of memory of the given size in bytes 
    and returns a pointer to the first byte of the block.
   - `void *calloc(size_t nmemb, size_t size)` - allocates a block of memory for an array of `nmemb` 
    elements, each of size `size` bytes, and initializes all bytes to zero.

2. Initialization:
   - `malloc()` does not initialize the memory block. 
    The content of the block is undefined and could contain garbage values.
   - `calloc()` initializes the memory block with zero values.

3. Return Value:
   - `malloc()` returns a pointer to the allocated memory block or `NULL` if the allocation fails.
   - `calloc()` returns a pointer to the allocated memory block or `NULL` if the allocation fails.

4. Performance:
   - `calloc()` is slightly slower than `malloc()` because it initializes the memory block.

5. Usage:
   - `malloc()` is typically used when you need to allocate memory for a single object or a structure.
   - `calloc()` is typically used when you need to allocate memory for an array of objects.

In summary, the main difference between `malloc()` and `calloc()` is that `calloc()` 
initializes the memory block with zero values, while `malloc()` does not. 
Additionally, `calloc()` is typically used to allocate memory for an array of objects, 
while `malloc()` is typically used to allocate memory for a single object or structure.
*/


int main(){
    int *a = malloc(sizeof(int));
    printf("value of a = %d\n", *a);
    free(a);
    return 0;
}