#include "Functions.h"

// Methods for DefinedInNumbersF
DefinedInNumbersF::DefinedInNumbersF(Pair<int, int>* data, size_t size) { 
    _size = size;
    //std::memcpy(_data, data, size * sizeof(Pair<int, int>));
    for(size_t i = 0; i < size; i++) {
        _data[i] = data[i];
    }
}

int DefinedInNumbersF::evaluate(int val) const {
    for(size_t i = 0; i < _size; i++) {
        if(_data[i].first() == val) {
            return _data[i].second();
        }
    }

    return 0;
}

bool DefinedInNumbersF::isDefined(int val) const {
    for(size_t i = 0; i < _size; i++) {
        if(_data[i].first() == val) {
            return true;
        }
    }
    return false;
}

// Methods for NotDefinedInNumbersF
NotDefinedInNumbersF::NotDefinedInNumbersF(int* data, size_t size) {
    _size = size;
    std::memcpy(_data, data, size * sizeof(int));
}

int NotDefinedInNumbersF::evaluate(int val) const {
    for(size_t i = 0; i < _size; i++) {
        if(_data[i] == val) {
            return 0;
        }
    }

    return val;
}

bool NotDefinedInNumbersF::isDefined(int val) const {
    for(size_t i = 0; i < _size; i++) {
        if(_data[i] == val) {
            return false;
        }
    }

    return true;
}

// Methods for ReturnOneAndZeroF
ReturnOneAndZeroF::ReturnOneAndZeroF(int* data, size_t size) {
    _size = size;
    std::memcpy(_data, data, size * sizeof(int));
}

int ReturnOneAndZeroF::evaluate(int val) const {
    for(size_t i = 0; i < _size; i++) {
        if(_data[i] == val) {
            return 1;
        }
    }

    return 0;
}

bool ReturnOneAndZeroF::isDefined(int val) const {
    return true;
}
