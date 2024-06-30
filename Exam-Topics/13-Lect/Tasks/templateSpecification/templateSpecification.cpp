#include <iostream>
using namespace std;


template <class T>
void print(const T& t) {
    cout << t << endl;
}

template <>
void print<char>(const char& t) {
    cout << "char " << t << endl;
}

int main() {
    char ch = '2';
    int n = 2;
    
    print(ch);
    print(n);
}