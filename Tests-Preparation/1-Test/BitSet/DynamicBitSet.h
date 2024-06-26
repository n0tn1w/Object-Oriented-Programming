#ifndef DYNAMIC_BIT_SET
#define DYNAMIC_BIT_SET

#include <cstdint>  // uint64_t
#include <stddef.h> // size_t

#include <iostream>


namespace ConstsDynamic {

    constexpr unsigned BUCKET_SIZE = sizeof(uint8_t) * 8;

};

class DynamicBitSet {


    uint8_t* _data;
    unsigned _N; // i didnt find what was the difference b/n size_t and unsigned

    unsigned getBucketIndex(unsigned) const;
    unsigned getBitIndex(unsigned) const;
    void validateIndex(unsigned) const;

public:

    DynamicBitSet(unsigned);
    DynamicBitSet(const DynamicBitSet&);
    DynamicBitSet& operator=(const DynamicBitSet&);
    ~DynamicBitSet();

    bool check(unsigned) const;
    void add(unsigned);
    void remove(unsigned);
    void print() const;

    friend DynamicBitSet section(const DynamicBitSet&, const DynamicBitSet&);
    friend DynamicBitSet unification(const DynamicBitSet&, const DynamicBitSet&); 

private:

    void free();
    void copyFrom(const DynamicBitSet&);

};
#endif