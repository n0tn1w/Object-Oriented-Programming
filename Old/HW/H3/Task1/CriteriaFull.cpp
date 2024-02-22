#include "CriteriaFull.h"

CriteriaFull::CriteriaFull(const int* arr, short n) : Criteria(arr, n) {}

bool CriteriaFull::contains(const int el) const
{
    for (int i = 0; i < n; i++) {
        if (elements[i] == el) {
            return true;
        }
    }
    
    return false;
}
