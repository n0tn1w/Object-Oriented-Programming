#include <iostream>
using namespace std;

class  A
{
public:
    int _x;
    A(int x) { _x = x;}
    A() { cout << "A()" << endl;}
    A(const A&) {cout << "CC A()" << endl;}
    A(A&&) {cout << "MM A()" << endl;}
    A& operator=(const A&) {cout << "OP= A" << endl; return *this;}
    A& operator=(A&&) {cout << "MM OP= A" << endl; return *this;}
    ~ A() {cout << "~A()" << endl;}
};

void f(A* data, A&& obj) {
    *data = std::move(obj);
}

void g(A* data, A&& obj) {
    data = new A(std::move(obj));
}

int main() {
    A* data = new A(2);
    A b(3);

    cout << "Functions" << endl;
    f(data, std::move(b));
    g(data, std::move(b));
    g(data, std::move(b));

}