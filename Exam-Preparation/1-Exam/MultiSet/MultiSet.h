#ifndef MULTI_SET
#define MULTI_SET
#include <stddef.h>
#include <cstdint>
#include <iostream>
using std::cout;
using std::endl;

namespace Consts {
    const size_t NUMBER_COUNT = 3;
    const size_t NUMBERS_IN_BUCKET = 4;
    const size_t BUCKET_SIZE = sizeof(uint8_t) * 8;
};

class MultiSet {

    uint8_t* _data;
    size_t _N;

    size_t getBucket(size_t) const;
    size_t getBitIndex(size_t) const;

public:

    MultiSet();
    MultiSet(size_t N);
    MultiSet(const MultiSet&);
    MultiSet& operator=(const MultiSet&);
    ~MultiSet();

    int count(size_t) const;
    bool add(size_t);
    bool remove(size_t);
    void print() const;

    friend MultiSet unify(const MultiSet& s1, const MultiSet& s2);
private:
    void free();
    void copyFrom(const MultiSet&);
};
#endif