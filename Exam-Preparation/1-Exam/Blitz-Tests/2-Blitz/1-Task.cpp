// 1. Ще се компилира ли следният код? Ако не, защо?

#include <iostream>

class A {
public:
    void f() const
    {
        g();
    }
    void g() const{}
};

int main() {
    A a;
    a.f();
}

// It will compile because g is a const function called by another const function
// if g is not const it would not compile