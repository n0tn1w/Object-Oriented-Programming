#include <iostream>
using std::cout;
using std::endl;

union  Data
{
    int i;
    short s;
};

bool isLittleEndianness() {
    Data uni;
    uni.i = 1;
    //uni.s = 3;
    return uni.s == 1;
}

int main() {
    cout << isLittleEndianness();
}