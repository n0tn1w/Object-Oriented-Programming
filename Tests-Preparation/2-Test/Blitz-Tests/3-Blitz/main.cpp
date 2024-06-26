#include <iostream>
using namespace std;

class Base {
public:
    int fun() { cout<< "B:F"<< endl; }
    int fun(int a) { cout<< "B:F" << a << endl;}
    int ba() {}
};

class Der : public Base {
public:
    int fun () {cout<< "D:F"<< endl;}
    int ba(int a) {}
};

int main() {
    Der d;
    d.fun(1);
    d.ba();
    d.Base::fun(1);
}