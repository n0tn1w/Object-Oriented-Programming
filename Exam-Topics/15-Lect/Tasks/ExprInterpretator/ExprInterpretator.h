#pragma once
#include <cstddef> 
#include <iostream>
#include <string_view>
#include <cstring>

#include "../Expr/Expr.h"
#include "../ExprFactory/ExprFactory.h"
#include "../StringView/StringView.h"

class ExprInterpretator {

public:

    ExprInterpretator(const char*);
    ExprInterpretator(const ExprInterpretator&);
    ExprInterpretator(ExprInterpretator&&);
    ExprInterpretator& operator=(const ExprInterpretator&);
    ExprInterpretator& operator=(ExprInterpretator&&);
    ~ExprInterpretator();

    bool isTautology() const;
    bool isContradiction() const;

private:

    Expr* extracExprFromString(const char*);

    bool checkAllPossible(bool) const;

    void free();
    void copyFrom(const ExprInterpretator&);
    void moveFrom(ExprInterpretator&&);

    Expr* _root = nullptr;
};