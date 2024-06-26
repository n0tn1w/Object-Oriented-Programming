#include "Negotiate.h"

Negotiate::Negotiate(Expr* expr) : UnaryExpr(expr) { }

Expr* Negotiate::clone() const {
    return new Negotiate(_expr);
}

bool Negotiate::eval(const BoolInterpretation& bi) const {
    return !(_expr->eval(bi));
}

