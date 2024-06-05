#include <iostream>
using namespace std;

class  A
{
public:
     A() { cout << "A()" << endl;}
     A(const A&) {cout << "CC A()" << endl;}
     A(A&&) {cout << "MM A()" << endl;}
    ~ A() {cout << "~A()" << endl;}
};

void f(A obj) {}

int main() {
    A obj; // A()
    f(obj); // CC A() ~A()
    f(A()); //A() ~A()
} // ~A()