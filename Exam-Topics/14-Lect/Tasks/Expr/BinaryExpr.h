#pragma once
#include "Expr.h"

// Abstract
class BinaryExpr : public Expr  {

public:

    BinaryExpr(Expr*, Expr*);
    ~BinaryExpr();
    void getVariableInExpr(BoolInterpretation&) const override;

protected:
    
    Expr* _left = nullptr;
    Expr* _right = nullptr;

};