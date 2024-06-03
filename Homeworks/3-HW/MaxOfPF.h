#pragma once
#include <stdexcept>
#include <limits.h>

#include "PFContainer.h"

class MaxOfPF : public PFContainer {

public:

    MaxOfPF(const PF* const*, size_t);
    MaxOfPF(PF**&&, size_t);

    PF* clone() const override;

protected:

    int evaluate(int) const override;
    bool isDefined(int) const override;

};