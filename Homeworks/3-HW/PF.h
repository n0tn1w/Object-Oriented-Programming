#pragma once
#include <cstddef>

#include "Pair.hpp"

// Abstract class
class PF {

public:
    
    virtual PF* clone() const = 0;
    virtual ~PF() = default;

    virtual Pair<int, bool> operator()(int) const = 0;

    // This two are implemented for requirements
    int evaluate(int) const;
    bool isDefined(int) const;

};