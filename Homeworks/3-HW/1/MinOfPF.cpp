#include "MinOfPF.h"

MinOfPF::MinOfPF(const PF* const* funcs, size_t size) : PFContainer(funcs, size) {}
MinOfPF::MinOfPF(PF**&& funcs, size_t size) : PFContainer(std::move(funcs), size) {}

Pair<int, bool> MinOfPF::operator()(int val) const {
    // if(isEmpty()) {
    //     throw std::out_of_range("No functions to be evaluated!");
    // }
    
    int currentMin = INT_MAX;
    for(size_t i = 0; i < _size; i++) {

         Pair<int, bool>  res = _data[i]->operator()(val);

         if(!res.second()) 
             return {0, false};

        if(currentMin > res.first()) {
            currentMin = res.first();
        }
    }

    return {currentMin, true};
}


PF* MinOfPF::clone() const {
    return new MinOfPF(*this);
}
