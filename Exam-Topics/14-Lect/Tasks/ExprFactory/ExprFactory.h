#pragma once

#include <stdexcept>

#include "../Expr/Expr.h"
#include "../StringView/StringView.h"
#include "../Expr/Expr.h"
#include "../Expr/Variable.h"
#include "../Expr/Negotiate.h"
#include "../Expr/Conjunction.h"
#include "../Expr/Disjunction.h"

// Static class
class ExprFactory {

public:

    static Expr* create(StringView str);

};