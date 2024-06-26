#include "StaticBitSet.h"
#include <iostream>
using std::cout;
using std::endl;

size_t StaticBitSet::getBucketIndex(size_t index) const{
    return index / Consts::BUCKET_SIZE;
}

size_t StaticBitSet::getBitIndex(size_t index) const {
    return index % Consts::BUCKET_SIZE;
}

bool StaticBitSet::check(size_t index) const {
    if(index > 1000) {
        //return false;
        throw "Index out of bounds";
    }

    size_t bucketIndex = getBucketIndex(index); 
    size_t bitIndex = getBitIndex(index);


    return _data[bucketIndex] & ( 1 << bitIndex);
}

void StaticBitSet::add(size_t index) {
    if(index > 1000) {
        //return false;
        throw "Index out of bounds";
    }

    size_t bucketIndex = getBucketIndex(index);
    size_t bitIndex = getBitIndex(index);

    _data[bucketIndex] |= (1 << bitIndex);
}

void StaticBitSet::remove(size_t index) {
    if(index > 1000) {
        //return false;
        throw "Index out of bounds";
    }

    size_t bucketIndex = getBucketIndex(index);
    size_t bitIndex = getBitIndex(index);

    uint8_t max = 255;
    max &= (0 << bitIndex);
    _data[bucketIndex] &= max;
}

void StaticBitSet::print() const {
    for(size_t i = 0; i < Consts::MAX_BUCKETS_COUNT; i++) {
        for(size_t k = 0; k < Consts::BUCKET_SIZE; k++) {
            bool xs = _data[i] & (1 << k);
            if(xs) {
                cout << i * Consts::BUCKET_SIZE + k << " ";
            } 
        }
    }
    cout << endl;
}

StaticBitSet unification(const StaticBitSet& l, const StaticBitSet& r) {
    StaticBitSet sbs;
    for(size_t i = 0; i < Consts::MAX_BUCKETS_COUNT; i++) {
        sbs._data[i] = l._data[i] | r._data[i];
    }

    return sbs;
}

StaticBitSet section(const StaticBitSet& l, const StaticBitSet& r) {
    StaticBitSet sbs;
    for(size_t i = 0; i < Consts::MAX_BUCKETS_COUNT; i++) {
        sbs._data[i] = l._data[i] & r._data[i];
    }

    return sbs;
}

