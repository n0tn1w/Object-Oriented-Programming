#include "BinaryExpr.h"

BinaryExpr::BinaryExpr(Expr* left, Expr* right) {
    _left  = left;
    _right = right;
 }

BinaryExpr::~BinaryExpr() {
    delete _left;
    delete _right;
}

void BinaryExpr::getVariableInExpr(BoolInterpretation& bi) const {
    _left->getVariableInExpr(bi);
    _right->getVariableInExpr(bi);
}