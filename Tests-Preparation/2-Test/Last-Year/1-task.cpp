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



void g() {
    throw 37;
}

void f() {
    B obj;
    g();
}

int main() {
    A obj;
    try {
        f();
    }catch(B& obj) {}
    catch(int obj) {}
}