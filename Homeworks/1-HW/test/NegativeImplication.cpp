#include <iostream>
using namespace std;;

int foo(int a, int b) { return !a || b; }

void bucket(uint64_t& a, const uint64_t b, int bucketSize) {

    uint64_t fin = 0;
    for (int i = sizeof(uint64_t)*8 -1 ; i >= bucketSize; --i) {

        int bit1 = (a >> i) & 1;
        int bit2 = (b >> i) & 1;
        int res  = bit1 ^ bit2;

        fin |= (res << (32 - (sizeof(uint64_t) * 8 - i)));
        cout << "Bit " << i << ": " << res << endl;
    }
    a = fin;    
}

int main() {
    int a = 97;
    int b = 85;
    int c = a ^ b;
    cout << c<< endl << endl;
     int result = 0;

    int num = 85; // Example integer
    int reversedNum = 0;

    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
        bool bit1 = (a >> i) & 1;
        bool bit2 = (b >> i) & 1;
        int bit = bit1 ^ bit2;
        cout << "Bit " << i << ": " << bit << endl;


        reversedNum |= (bit << (32 - (sizeof(int) * 8 - i)));
    }
    cout << reversedNum;



    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
        int bit = (reversedNum >> i) & 1;
        //cout << "Bit " << i << ": " << bit << endl;
    }

    int bit = !(!0 || 1);

    uint64_t aa = 97;
    uint64_t bb = 85;

    for(int i = sizeof(uint64_t) * 8 - 1; i >=0; --i) {
        bool byte1 = (aa >> i) & 1;
        bool byte2 = (bb >> i) & 1;
        bool res = byte1 ^ byte2;

    }

    bucket(aa, bb, 0);
    cout<< endl << aa << endl;

     //cout << bit;

    //      void bucket(uint64_t& a, const uint64_t b, int bucketSize) {

    //     uint64_t fin = 0;
    //     for (int i = sizeof(uint64_t)*8 - 1 ; i >= (63 - bucketSize); --i) {

    //         int bit1 = (a >> i) & 1;
    //         int bit2 = (b >> i) & 1;
    //         int res  = bit1 ^ bit2;

    //         fin |= (res << (32 - (sizeof(uint64_t) * 8 - i)));

    //         cout << "Bit " << i << ": " << res << endl;
    //     }
    //     a = fin;    
    //     cout << "Fin: " << fin<< endl;
    // }
}