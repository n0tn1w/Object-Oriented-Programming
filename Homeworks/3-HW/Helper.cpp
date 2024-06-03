#include "Helper.h"

void Helper::SelectionSort(int* arr, size_t size) {

    for(size_t i = 0; i < size - 1; i++) {
        int minElt = arr[i];
        int minIndex = i;

        for(size_t k = i + 1; k < size; k++) {
            if(minElt > arr[k]) {
                minElt = arr[k];
                minIndex = k;
            }
        }

        if(i != minIndex) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}