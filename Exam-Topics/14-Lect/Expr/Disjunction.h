#include "BinaryExpr.h"

class Disjunction : public BinaryExpr{

public:

    Disjunction(Expr*, Expr*);

    Expr* clone() const override;
    bool eval(BoolInterpretation&) const override;

};