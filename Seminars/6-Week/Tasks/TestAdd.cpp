#include <iostream>
using namespace std;


int main() {
    uint64_t a = 1;
    uint64_t th = 32;
    uint64_t one = 1;
    cout << "First: " << (a & (one << th)) << endl;

    uint64_t a2 = 1;
    uint64_t th2 = 32;
    cout << "Second: " << (a2 & (1 << th2)) << endl;
}