#include <iostream>
using namespace std;

class Base {
private:
    int p;
protected:
    double pr;
public:
    short pc;
};

class Der : private Base {
    void f() {
        //Base::p
    }
};

int main() {
    Der d;
    //d.pc;
}