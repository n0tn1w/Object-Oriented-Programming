#include "Functions.h"

// Methods for DefinedInNumbersF
DefinedInNumbersF::DefinedInNumbersF(Pair<int, int>* data, size_t size) { 
    _size = size;
    //std::memcpy(_data, data, size * sizeof(Pair<int, int>));
    for(size_t i = 0; i < size; i++) {
        _data[i] = data[i];
    }
}

Pair<int, bool> DefinedInNumbersF::operator()(int val) const {
    for(size_t i = 0; i < _size; i++) {
        if(_data[i].first() == val) {
            return {_data[i].second(), true};
        }
    }
    return {0, false};
}


// Methods for NotDefinedInNumbersF
NotDefinedInNumbersF::NotDefinedInNumbersF(int* data, size_t size) {
    _size = size;
    std::memcpy(_data, data, size * sizeof(int));
}

Pair<int, bool> NotDefinedInNumbersF::operator()(int val) const {
    for(size_t i = 0; i < _size; i++) {
        if(_data[i] == val) {
            return {0, false};
        }
    }
    return {val, true};
}


// Methods for ReturnOneAndZeroF
ReturnOneAndZeroF::ReturnOneAndZeroF(int* data, size_t size) {
    _size = size;
    std::memcpy(_data, data, size * sizeof(int));
}

Pair<int, bool> ReturnOneAndZeroF::operator()(int val) const {
    for(size_t i = 0; i < _size; i++) {
        if(_data[i] == val) {
            return {1, true};
        }
    }
    return {0, true};
}
