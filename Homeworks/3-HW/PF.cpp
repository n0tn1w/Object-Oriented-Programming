#include "PF.h"

int PF::evaluate(int val) const {
    return (*this)(val).first();
}

bool PF::isDefined(int val) const {
    return (*this)(val).second();
}
