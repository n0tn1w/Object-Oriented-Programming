#pragma once
#include "Expr.h"
#include "UnaryExpr.h"

class Negotiate : public UnaryExpr {

public:

    Negotiate(Expr*);

    Expr* clone() const override;
    bool eval(BoolInterpretation&) const override;
};