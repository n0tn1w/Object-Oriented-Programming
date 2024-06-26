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

void f(A obj) { }
void g(A&& obj) { }

int main() {
    A obj; // A()
    f(std::move(obj)); // MM A() ~A()
    g(std::move(obj));
} // ~A()