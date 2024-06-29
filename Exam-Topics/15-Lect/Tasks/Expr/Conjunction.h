#pragma once
#include "Expr.h"
#include "BinaryExpr.h"

class Conjuction : public BinaryExpr {

public:

    Conjuction(Expr*, Expr*);

    Expr* clone() const override;
    bool eval(const BoolInterpretation&) const override;
};