#include<iostream>
using std::cout;
using std::endl;

struct A {
    int x;
    int y;
};

A&& xvalue() {
    A obj = {5,6};
    return std::move(obj);
}

A prvalue() {
    A obj = {5,6}; // NRVO is done here
    return obj;
}

A& lvaue() {
    A obj = {5,6};
    return obj;
}

const A& lconstvalue() { // Works before C++11
    A obj = {5,6};
    return obj;
}

int main() {
    {
        // This is the only configuration that works
        const A& ref1 = prvalue();
        A&& ref2 = prvalue();
        A copy = prvalue();

        cout << ref1.x << ref2.x << copy.x << endl;
    }
}