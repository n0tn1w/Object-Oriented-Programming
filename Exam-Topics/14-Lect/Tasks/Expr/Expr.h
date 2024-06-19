#pragma once

#include "../BoolInterpretation/BoolInterpretation.h"

// Abstract
class Expr {

public:
    Expr() = default;

    Expr(const Expr&) = delete;
    Expr& operator=(const Expr&) = delete;

    virtual Expr* clone() const = 0;
    virtual bool eval(BoolInterpretation&) const = 0;
    virtual void getVariableInExpr(BoolInterpretation&) const = 0;

    virtual ~Expr() = default;
};