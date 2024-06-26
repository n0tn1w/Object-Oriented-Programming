//1. Има ли проблем със следния код? Ако да, какъв?

#include <iostream>

void f(char*& ptr, unsigned n) {
	ptr = new char[n];
	for (int i = 0; i < n; i++)
		std::cin >> ptr[i];
}

int main() {
	char* ptr = nullptr;
	unsigned n = 3;
	f(ptr, n);
	delete[] ptr;
}

// So the value of the ptr wont be change outside of the f functions
// coz it is passed as a pointer copy not as ref