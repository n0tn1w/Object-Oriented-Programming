#include "BinaryExpr.h"

class Disjunction : public BinaryExpr{

public:

    Disjunction(Expr*, Expr*);

    Expr* clone() const override;
    bool eval(const BoolInterpretation&) const override;

};