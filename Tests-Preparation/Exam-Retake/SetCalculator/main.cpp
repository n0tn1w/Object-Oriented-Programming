#pragma once
#include <iostream>
#include "SetCalculator.cpp"
using namespace std;

int main()
{
    //v - union
    //^ - intersection
        // '\' - set minus
        // '!' - complement
        // 'x' - relative complement

    SetCalculator s("(((A^B)vC)vX)");

    SigmaAlgebra el;
    el.setAt('A', true); //element is in set A
    el.setAt('B', false); // element is NOT in set B
    el.setAt('C', true); // element is in set C

    std::cout << s.isElementIn(el);

    SetCalculator s1("(A^B)");
    SetCalculator s2("(!((!A)v(!B)))");
    std::cout << (s1 == s2); // true (De morgan laws)
}