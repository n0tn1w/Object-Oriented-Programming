#include <iostream>
using namespace std;

struct X {
    static int count;

    X() {
        cout << "X()" << endl;
        if(count == 2)
            throw 3;
        count++;
    }

    ~ X() {
        cout << "~ X()" << endl;
    }
};

int X::count = 0;

int main() {
    try {
        X* arr = new X[10];
    }catch(int) {}

}