#include <iostream>
using namespace std;;

void bucketTune(uint64_t& a, size_t tuneMix, size_t& offset, size_t len) {
    uint64_t fin = a;
    int i = offset;
    for(; i < len - 1; i += tuneMix) {
        int bit = (a << i) & 1; 
        int resBit = bit || 1;
        cout << "Bit " << i << " :" << resBit << endl;
        fin |= (resBit << i);
    }
    a = fin;
    cout << "Offset: " << i % tuneMix << endl;
    offset = i % tuneMix;
}

int main() {
    uint64_t a = 17990; // 0100 0110 0100 0110
    size_t tuneMix = 3; // 0100 1111 0110 0110
    size_t offset = tuneMix - 1;
    bucketTune(a, tuneMix, offset, 16); // 20326
    cout << a;

}