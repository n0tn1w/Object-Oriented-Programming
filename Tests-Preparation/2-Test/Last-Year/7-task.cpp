#include <iostream>
using namespace std;

class  A{
public:
     A() { cout << "A()" << endl;}
    ~ A() {cout << "~A()" << endl;}
};
class  B{
public:
     B() { cout << "B()" << endl;}
    ~ B() {cout << "~B()" << endl;}
};
class  C{
public:
     C() { cout << "C()" << endl;}
    ~ C() {cout << "~C()" << endl;}
};
class  D{
public:
     D() { cout << "D()" << endl;}
    ~ D() {cout << "~D()" << endl;}
};
class  E{
public:
     E() { cout << "E()" << endl;}
    ~ E() {cout << "~E()" << endl;}
};

class X : A, B, C {
public:
    D obj1;
    E obj2;
    X(): obj2(), C(), B(), A(), obj1() { 
        cout << "X()" << endl;
    }
    ~X() { cout << "~X()" << endl;}
};

int main() {
    X z;
}