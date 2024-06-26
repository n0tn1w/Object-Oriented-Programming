// 2. Ще се компилира ли следният код? Ако не, защо?

#include <iostream>

class A {
public:
    void t() {}
    void foo() const
    {
       // t();
    }
};

// It will not complie coz t is not const