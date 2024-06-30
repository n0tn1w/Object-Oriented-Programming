#include "Function.hpp"
#include <iostream>
using std::cout;
using std::endl;

class FunctionWithContext {

private:

    int a;
    int b;
    int c;

public:

    int operator()(int val) {
        return (a * b * c) / val;
    }

};

struct Example {

    void operator()(int val) {
        cout << "Example " << val << endl;
    }
};

struct WrongExample {
    void operator()(int val, int n) {
        cout << "Not reached" << endl;
    }
};


void func(int val) {
    cout << "Func " << val << endl;
}

int main() {
    Function<Example> f1{Example()};
    Function<void(*)(int)> f2{func};
    Function<void(*)(int)> f3{[](int x){ cout << "Lambda " << x << endl;}};
    f1(2);
    f2(3);
    f3(4);

    // Function<WrongExample> f4{WrongExample()};
    // f4();
}