#include <iostream>
using namespace std;

struct A
{
    virtual void f() = 0;
};

void A::f() {
    cout << "afa";
}

struct B : A {
};

struct C : A {
    void f() {
        cout << "Afwa";
    }
};

int main () {
    // B b; 
    // B is abrstract class as well

    C as;
}