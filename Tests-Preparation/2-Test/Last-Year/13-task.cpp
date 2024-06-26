#include <iostream>
using namespace std;

struct Base
{
    Base() {
        f();
    }
    
    virtual void f() {
        cout << "Base::f" << endl;
    }

    ~Base() {
        f();
    }
};

struct Der : Base {
    void f() override {
        cout << "Der::f" << endl;
    }
};

int main() {
    Der d;
    cout << "---" << endl;
    d.f();
    cout << "..." << endl;
    return 0;
}

