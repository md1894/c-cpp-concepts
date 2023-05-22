#include <iostream>
#include <cstring>

class MemoryPool {
private:
    char* memoryBlock;
    size_t blockSize;
    size_t numBlocks;
    bool* allocationMap;

public:
    MemoryPool(size_t blockSize, size_t numBlocks) : blockSize(blockSize), numBlocks(numBlocks) {
        memoryBlock = new char[blockSize * numBlocks];
        allocationMap = new bool[numBlocks];
        std::memset(allocationMap, false, numBlocks * sizeof(bool));
    }

    ~MemoryPool() {
        delete[] memoryBlock;
        delete[] allocationMap;
    }

    void* allocate() {
        for (size_t i = 0; i < numBlocks; ++i) {
            if (!allocationMap[i]) {
                allocationMap[i] = true;
                return memoryBlock + (i * blockSize);
            }
        }
        return nullptr; // No free blocks available
    }

    void deallocate(void* ptr) {
        char* blockPtr = reinterpret_cast<char*>(ptr);
        size_t blockIndex = (blockPtr - memoryBlock) / blockSize;

        if (blockIndex >= 0 && blockIndex < numBlocks && allocationMap[blockIndex]) {
            allocationMap[blockIndex] = false;
        }
    }
};

int main() {
    MemoryPool pool(sizeof(int), 5);

    int* ptr1 = static_cast<int*>(pool.allocate());
    *ptr1 = 10;
    std::cout << "Value at ptr1: " << *ptr1 << std::endl;

    int* ptr2 = static_cast<int*>(pool.allocate());
    *ptr2 = 20;
    std::cout << "Value at ptr2: " << *ptr2 << std::endl;

    pool.deallocate(ptr1);

    int* ptr3 = static_cast<int*>(pool.allocate());
    *ptr3 = 30;
    std::cout << "Value at ptr3: " << *ptr3 << std::endl;

    pool.deallocate(ptr2);
    pool.deallocate(ptr3);

    return 0;
}

