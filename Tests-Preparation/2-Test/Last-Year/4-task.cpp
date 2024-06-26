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

void f(A& obj) {
    std::cout << 1;
}

void f(A&& obj) {
    std::cout << 2;
}

void g(A&& obj) {
    f(obj);
}

int main() {
    g(A());
}