#include "Conjunction.h"

Conjuction::Conjuction(Expr* l, Expr* r) : BinaryExpr(l, r) { }

Expr* Conjuction::clone() const {
    return new Conjuction(_left, _right);
}

bool Conjuction::eval(BoolInterpretation& bi) const {
    return _left->eval(bi) && _right->eval(bi);
}