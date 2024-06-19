#include "ExprFactory.h"

Expr* ExprFactory::create(StringView str) {
    StringView view = str.substr(1, str.GetSize() - 2);

    if(view.GetSize() == 1)
        return new Variable(view[0]);

    size_t bracketCount = 0;
    for(size_t i = 0; i < view.GetSize(); i++) {
        
        if(view[i] == '(') {
            bracketCount++;
        } else if(view[i] == ')') {
            bracketCount--;
        } else if(bracketCount == 0) {
            
            if(view[i] == '&') {
                return new Conjuction(create(view.substr(0, i - 1)), create(view.substr(i + 1, view.GetSize() - 1)));
            } else if (view[i] == '|') {
                return new Disjunction(create(view.substr(0, i - 1)), create(view.substr(i + 1, view.GetSize() - 1)));
            } else if(view[i] == '!') {
                return new Negotiate(create(view.substr(1, view.GetSize() - 1)));
            }
        }
    }
    throw std::runtime_error("ragi tak tak");
}
