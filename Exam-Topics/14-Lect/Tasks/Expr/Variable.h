#pragma once
#include "Expr.h"

class Variable : public Expr {

public:

    Variable(char ch);

    Expr* clone() const override;
    bool eval(BoolInterpretation&) const override;
    void getVariableInExpr(BoolInterpretation&) const override;

private:

    char _ch;

};