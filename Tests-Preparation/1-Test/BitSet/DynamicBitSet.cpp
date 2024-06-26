#include "DynamicBitSet.h"
using std::cout;
using std::endl;

DynamicBitSet::DynamicBitSet(unsigned N) {
    if(N > 1000) {
        throw "Index out of bound! For Dynamic Bit Set!";
    }

    _N = N;
    _data = new uint8_t[N];
}

void DynamicBitSet::copyFrom(const DynamicBitSet& oth) {
    _N = oth._N;
    _data = new uint8_t[oth._N];
    for(unsigned i = 0; i < oth._N; i++) {
        _data[i] = oth._data[i];
    }
}

void DynamicBitSet::free() {
    _N = 0;
    delete [] _data;
    _data = nullptr;
}

DynamicBitSet::DynamicBitSet(const DynamicBitSet& oth) {
    copyFrom(oth);
}

DynamicBitSet& DynamicBitSet::operator=(const DynamicBitSet& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }
    return *this;
}

DynamicBitSet::~DynamicBitSet() {
    free();
}

void DynamicBitSet::validateIndex(unsigned index) const{
    if(index >= _N) {
        throw "Index out of range!";
    }

}

unsigned DynamicBitSet::getBucketIndex(unsigned index) const{
    return index / ConstsDynamic::BUCKET_SIZE;
}

unsigned DynamicBitSet::getBitIndex(unsigned index) const{
    return index % ConstsDynamic::BUCKET_SIZE;
}

bool DynamicBitSet::check(unsigned index) const {
    validateIndex(index);

    unsigned bucketIndex = getBucketIndex(index);
    unsigned bitIndex = getBitIndex(index);

    return _data[bucketIndex] & ( 1 << bitIndex);
}

void DynamicBitSet::add(unsigned index) {
    validateIndex(index);

    unsigned bucketIndex = getBucketIndex(index);
    unsigned bitIndex = getBitIndex(index);
    
    _data[bucketIndex] |= (1 << bitIndex);
}

void DynamicBitSet::remove(unsigned index) {
    validateIndex(index);

    unsigned bucketIndex = getBucketIndex(index);
    unsigned bitIndex = getBitIndex(index);
    
    uint8_t mask = 255;
    mask ^= (1 << bitIndex);
    _data[bucketIndex] &= mask;

    //uint8_t mask =  -(1 << bitIndex);
    //_data[bucketIndex] &= mask;
}

void DynamicBitSet::print() const {
    for(unsigned i = 0; i < _N; i++) {
        if(check(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

DynamicBitSet section(const DynamicBitSet& l, const DynamicBitSet& r) {
    DynamicBitSet dbs(std::min(l._N, r._N));

    unsigned buckets = dbs._N / ConstsDynamic::BUCKET_SIZE + 1;
    for(unsigned i = 0; i < buckets; i++) {
        dbs._data[i] = l._data[i] & r._data[i];
    }

    return dbs;
} 

DynamicBitSet unification(const DynamicBitSet& l, const DynamicBitSet& r) {
    DynamicBitSet dbs(std::max(l._N, r._N));

    unsigned minN = std::min(l._N, r._N);
    unsigned buckets = minN / ConstsDynamic::BUCKET_SIZE + 1;
    for(unsigned i = 0; i < buckets ; i++) {
        dbs._data[i] = l._data[i] | r._data[i];
    }
    const DynamicBitSet& tempDbs = l._N > r._N ? l : r;
    unsigned maxBuckets = tempDbs._N / ConstsDynamic::BUCKET_SIZE + 1;

    for(unsigned i = minN; i < maxBuckets; i++) {
        dbs._data[i] = tempDbs._data[i];
    }

    return dbs;

}