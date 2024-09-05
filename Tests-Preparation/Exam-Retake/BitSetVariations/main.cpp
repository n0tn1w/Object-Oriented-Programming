#include <iostream>
#include "SetByString.cpp"
#include "SetByCriteria.cpp"

bool isPrime(int n) {
	size_t del;
	for (int i = 1; i < n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

bool isOdd(int n) {
	return n % 2 != 0;
}

int main() {

	SetByCriteria s1(10, isPrime, isOdd);

	s1.print(); // {2}
	std::cout << std::endl << "---" << std::endl;

	SetByString s(300, "1 2 3");

	s.print(); // {1, 2, 3}

	s.setAt(1, '1');
	std::cout << std::endl;

	s.print(); // {3, 112}

	//Bitset b(10);
	//b.print();
	//std::cout << std::endl;
	//b.add(0);
	//b.add(10);
	//b.print();
	//std::cout << std::endl;
	//b.remove(0);
	//b.remove(10);
	//b.print();
	//std::cout << std::endl;
	//b.add(0);
	//b.add(10);	b.add(0);
	//b.add(10);	b.add(0);
	//b.add(10);	b.add(0);
	//b.add(10);	b.add(0);
	//b.add(10);
	//b.print();
	//std::cout << std::endl;
	//std::cout << std::endl;
}