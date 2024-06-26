// 5. Какво ще отпечата следният код на екрана?
#include <iostream>
#include <cstddef>

union {
	uint64_t number = 0;
	char str[8];
} example;

int main() {
	example.number = 3;
	example.str[1] = 1;
	std::cout << example.number;
}
// 256. So here the union doesnt delete the old data that it already has and it read