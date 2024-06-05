#include <iostream>
using namespace std;

struct Base {
    int a = 1;
};

struct Der : Base {
    int b = 2;
    int c = 3;
};

void f(Base* arr) { //123123123
    cout << arr[0].a << " " << arr[1].a << " " << arr[2].a << " " << arr[5].a << endl;
}

int main() {
    Der der[3];
    f(der);
}