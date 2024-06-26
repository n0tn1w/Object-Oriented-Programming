#ifndef STATIC_BIT_SET
#define STATIC_BIT_SET

#include <cstdint>  // uint64_t
#include <stddef.h> // size_t

namespace Consts{
    const size_t MAX_ELEMENTS_COUNT = 1028;
    const size_t BUCKET_SIZE = sizeof(uint8_t) * 8; // 8
    const size_t MAX_BUCKETS_COUNT = 1028 / BUCKET_SIZE;
};

class StaticBitSet {

    uint8_t _data[Consts::MAX_BUCKETS_COUNT] = { 0 }; // 1028 bits for use :)

    size_t getBucketIndex(size_t) const;
    size_t getBitIndex(size_t) const;

public:

    StaticBitSet() = default;

    void add(size_t);
    void remove(size_t);
    bool check(size_t) const;
    void print() const;

    friend StaticBitSet unification(const StaticBitSet&, const StaticBitSet&);
    friend StaticBitSet section(const StaticBitSet&, const StaticBitSet&);
};
#endif