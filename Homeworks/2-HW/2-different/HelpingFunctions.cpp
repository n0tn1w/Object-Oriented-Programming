#include "HelpingFunctions.h"

void copyShortArray(short* dest, const short* source, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

size_t getNextPowerOfTwo(unsigned int n)
{
    size_t step = 1;

    while ((n >> step) > 0) {
        n |= n >> step;
        step *= 2;
    }

    return n + 1;
}

void printMatrix(bool* matrix[], size_t size)
{
    for (int i = 0; i < size; i++) {
        for (int j = size-1; j >= 0; j--) {
            if (matrix[i][j]) {
                std::cout << 1;
            }
            else {
            std::cout << 0;
            }
            
        }
        std::cout << std::endl;
    }
}

size_t convertToindex(int value, int size)
{
    return value + size;
}

