#include "Variable.h"

Variable::Variable(char ch) {
    // validations maybe?
    _ch = ch;
}

Expr* Variable::clone() const {
    return new Variable(_ch);
}

bool Variable::eval(const BoolInterpretation& bi) const {
    return bi.getCharAt(_ch);
}

void Variable::getVariableInExpr(BoolInterpretation& bi) const {
    bi.setCharAt(_ch, true);
}