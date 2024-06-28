#include <iostream>
using namespace std;

struct A {
    virtual void f() const = 0;
};

void A::f() const {
    std::cout << "hi";
}

struct B : A
{
    void f() const override {
        A::f();
        std::cout << " hello";
    }
};


int main() {
    B b;
    b.f();
}