#include "UnaryExpr.h"

UnaryExpr::UnaryExpr(Expr* expr) {
    _expr = expr;
}

UnaryExpr::~UnaryExpr() {
    delete _expr;    
}

void UnaryExpr::getVariableInExpr(BoolInterpretation& bi) const {
    _expr->getVariableInExpr(bi);
}