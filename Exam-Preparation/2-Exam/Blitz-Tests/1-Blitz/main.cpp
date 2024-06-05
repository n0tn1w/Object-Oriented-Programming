#include <iostream>
#include "a.cpp"
#include "b.cpp"
using namespace std;

static int a; 
static double b;

void foo() {
    static int var;
    var++;
    cout << var << " ";
}


class A {

public:
    static int cnt;
    A() {
        cnt++;
    }
};

int A::cnt;

int main() {
    //cout << a << " " << b;

    for(int i = 0; i < 3; i++) {
        foo();
    }
    cout << endl;
    A a;
    cout << "a: " << A::cnt; 
}