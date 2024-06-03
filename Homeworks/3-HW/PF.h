#pragma once
#include <cstddef>

#include "Pair.hpp"

// Abstract class
class PF {

public:
    
    virtual PF* clone() const = 0;
    virtual ~PF() = default;

    Pair<int, bool> operator()(int) const;
    virtual int evaluate(int) const = 0;
    virtual bool isDefined(int) const = 0;

};