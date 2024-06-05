#include <iostream>
using namespace std;

class  A
{
public:
     A() { cout << "A()" << endl;}
    ~ A() {cout << "~A()" << endl;}
};
class  B
{
public:
     B() { cout << "B()" << endl;}
    ~ B() {cout << "~B()" << endl;}
};

struct X {
    A a;
    B b;
    X() {
        cout << "X()" << endl;
        throw 3;
    }

    ~ X() {
        cout << "~ X()" << endl;
    }
};

int main() {
    try{
        X x;
    }catch(int) {}
}
