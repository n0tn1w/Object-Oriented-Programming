#pragma once
#include <stdexcept>
#include <limits.h>

#include "PFContainer.h"

class MinOfPF : public PFContainer {

public:

    MinOfPF(const PF* const*, size_t);
    MinOfPF(PF**&&, size_t);

    PF* clone() const override;

protected:

    int evaluate(int) const override;
    bool isDefined(int) const override;

};