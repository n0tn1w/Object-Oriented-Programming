#include "MaxOfPF.h"

MaxOfPF::MaxOfPF(const PF* const* funcs, size_t size) : PFContainer(funcs, size) {}
MaxOfPF::MaxOfPF(PF**&& funcs, size_t size) : PFContainer(std::move(funcs), size) {}

int MaxOfPF::evaluate(int val) const {
    // if(isEmpty()) {
    //     throw std::out_of_range("No functions to be evaluated!");
    // }
    
    int currentMax = INT_MIN;
    for(size_t i = 0; i < _size; i++) {
        int evaluateFunction = _data[i]->evaluate(val);

        if(currentMax < evaluateFunction) {
            currentMax = evaluateFunction;
        }
    }
    return currentMax;
}

bool MaxOfPF::isDefined(int val) const {
    for(size_t i = 0; i < _size; i++) {

        bool res = _data[i]->isDefined(val);

        if(!res) 
            return false;
    }

    return true;
}

PF* MaxOfPF::clone() const {
    return new MaxOfPF(*this);
}
