#include "MaxOfPF.h"

MaxOfPF::MaxOfPF(const PF* const* funcs, size_t size) : PFContainer(funcs, size) {}
MaxOfPF::MaxOfPF(PF**&& funcs, size_t size) : PFContainer(std::move(funcs), size) {}

Pair<int, bool> MaxOfPF::operator()(int val) const {
    // if(isEmpty()) {
    //     throw std::out_of_range("No functions to be evaluated!");
    // }
    
    int currentMin = INT_MIN;
    for(size_t i = 0; i < _size; i++) {

         Pair<int, bool>  res = _data[i]->operator()(val);

         if(!res.second()) 
             return {0, false};

        if(currentMin < res.first()) {
            currentMin = res.first();
        }
    }

    return {currentMin, true};
}

PF* MaxOfPF::clone() const {
    return new MaxOfPF(*this);
}
