#include "PF.h"

Pair<int, bool> PF::operator()(int val) const {
    bool res = isDefined(val);
    if(!res) 
        return { 0, false };
    return { evaluate(val), true };
}
