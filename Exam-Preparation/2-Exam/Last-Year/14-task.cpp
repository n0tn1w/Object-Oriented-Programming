#include <iostream>
using namespace std;

void s(unsigned n) {
    int arr[n];
    cout << arr[0];
}

template <unsigned n>
void st() {
    int arr[n];
    cout << arr[0];
}

int main() {
    s(3);
    st<3>();
}