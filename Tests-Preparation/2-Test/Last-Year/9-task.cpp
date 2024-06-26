#include <iostream>
using namespace std;

struct A {
    char* c;
    int i;
    virtual void f() { }
    virtual void g() { }

};

int main() {
    cout << sizeof(A);
}