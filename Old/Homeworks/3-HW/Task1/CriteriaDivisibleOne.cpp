#include "CriteriaDivisibleOne.h"

CriteriaDivisibleOne::CriteriaDivisibleOne(const int* arr, short n) : Criteria(arr, n) {}

bool CriteriaDivisibleOne::contains(const int el) const
{
    int divisorCount = 0;
    for (int i = 0; i < n; i++) {
        if (el % elements[i] == 0) {
            divisorCount++;
            if (divisorCount > 1) {
                return false; 
            }
        }
    }
    return divisorCount == 1;
}
