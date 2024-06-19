#pragma once
#include "Expr.h"

// Abstract
class UnaryExpr : public Expr  {

public:

    UnaryExpr(Expr*);
    ~UnaryExpr();
    void getVariableInExpr(BoolInterpretation&) const override;

protected:
    
    Expr* _expr = nullptr;

};