#include "Disjunction.h"

Disjunction::Disjunction(Expr* l, Expr* r) :BinaryExpr(l, r) {}

Expr* Disjunction::clone() const {
    return new Disjunction(_left, _right);
}

bool Disjunction::eval(const BoolInterpretation& bi) const {
    return _left->eval(bi) || _right->eval(bi);
}