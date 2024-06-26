//2. Какво връщат sizeof и alignof на следните структури?

#include <iostream>
using namespace std;

struct Empty {};

struct A{
	Empty obj1;
	int a;
	char b;
	double c[3];
};

int main() {
    std::cout << sizeof(Empty) << " " << alignof(Empty) << endl;
    std::cout << sizeof(A) << " " << alignof(A) << endl;
}

// Predictions 1, 1 | 40, 8