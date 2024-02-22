#include "CriteriaFactory.h"

Criteria* criteriaFactory(short t, const int* arr, short n)
{
    if (t == 0) {
        return new CriteriaFull(arr, n);
    }
    else if (t == 1) {
        return new CriteriaDivisibleNone(arr, n);
    }
    else if (t == 2) {
        return new CriteriaDivisibleOne(arr, n);
    }
    else {
        throw logic_error("Error! Invalid Criteria creation!");
    }

    return nullptr;
}
