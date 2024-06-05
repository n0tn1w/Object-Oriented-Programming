#include <iostream>
using namespace std;

struct Base {

    Base() = delete;
};

struct Der :Base
{
    Der() { }
};

int main() {
    Der d;
}
