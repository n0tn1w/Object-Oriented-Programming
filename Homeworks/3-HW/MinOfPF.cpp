#include "MinOfPF.h"

MinOfPF::MinOfPF(const PF* const* funcs, size_t size) : PFContainer(funcs, size) {}
MinOfPF::MinOfPF(PF**&& funcs, size_t size) : PFContainer(std::move(funcs), size) {}

int MinOfPF::evaluate(int val) const {
    // if(isEmpty()) {
    //     throw std::out_of_range("No functions to be evaluated!");
    // }
    
    int currentMin = INT_MAX;
    for(size_t i = 0; i < _size; i++) {
        int evaluateFunction = _data[i]->evaluate(val);

        if(currentMin > evaluateFunction) {
            currentMin = evaluateFunction;
        }
    }
    return currentMin;
}

bool MinOfPF::isDefined(int val) const {
    for(size_t i = 0; i < _size; i++) {

        bool res = _data[i]->isDefined(val);

        if(!res) 
            return false;
    }

    return true;
}

PF* MinOfPF::clone() const {
    return new MinOfPF(*this);
}
