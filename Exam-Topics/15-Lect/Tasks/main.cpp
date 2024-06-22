#include "ExprInterpretator/ExprInterpretator.h"
#include <iostream>
using std::cout;

int main() {
    ExprInterpretator ei("((!(p))|(p))");
    cout << ei.isTautology();
}