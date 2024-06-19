#include "ExprInterpretator.h"


Expr* ExprInterpretator::extracExprFromString(const char* str) {
    
    size_t strLength = std::strlen(str);
    StringView initial(str, strLength);

    return ExprFactory::create(initial);
}   

bool ExprInterpretator::checkAllPossible(bool val) const {
    BoolInterpretation bi;
    _root->getVariableInExpr(bi);
    
    size_t vars = bi.turnOnCount();
    size_t permutation = (1 << vars);
    
    for(size_t i = 0; i < permutation; i++) {
        BoolInterpretation gen = bi;
        gen.modify(i);

        if(_root->eval(gen) != val) {
            return false;
        }
    }  

    return true;
}


bool ExprInterpretator::isTautology() const {
    return checkAllPossible(true);
}

bool ExprInterpretator::isContradiction() const {
    return checkAllPossible(false);
}

void ExprInterpretator::free() {
    delete _root;
}

void ExprInterpretator::copyFrom(const ExprInterpretator& oth) {
    _root = oth._root->clone();
}

void ExprInterpretator::moveFrom(ExprInterpretator&& oth) {
    _root = oth._root;
    oth._root = nullptr;
}

ExprInterpretator::ExprInterpretator(const char* str) {
    _root = extracExprFromString(str);
}
ExprInterpretator::ExprInterpretator(const ExprInterpretator& oth) {
    copyFrom(oth);
}
ExprInterpretator::ExprInterpretator(ExprInterpretator&& oth) {
    moveFrom(std::move(oth));
}
ExprInterpretator& ExprInterpretator::operator=(const ExprInterpretator& oth){
    if(this != &oth) {
        free();
        copyFrom(oth);
    }
    return *this;
}
ExprInterpretator& ExprInterpretator::operator=(ExprInterpretator&& oth) {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }
    return *this;
}
ExprInterpretator::~ExprInterpretator() { 
    free(); 
}