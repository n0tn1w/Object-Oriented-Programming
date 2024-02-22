#include "CriteriaDivisibleNone.h"

CriteriaDivisibleNone::CriteriaDivisibleNone(const int* arr, short n) : Criteria(arr, n) {}

bool CriteriaDivisibleNone::contains(const int el) const
{
    for (int i = 0; i < n; i++) {
        if (el % elements[i] == 0) {
            return false;
        }
    }
    return true;
}
