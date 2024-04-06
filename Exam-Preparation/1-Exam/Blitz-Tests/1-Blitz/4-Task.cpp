// 4. Отворили сте файл в режим за четене със следното съдържание:

// OOP blitz test 2024

// Забележка: Кавичките не се броят към съдържанието на файла

// Какво ще се изведе на конзолата след изпълнение на следния код?

#include <iostream>
#include <sstream>
using std::ios;

int main() {
    std::stringstream file("OOP blitz test 1024");

    char symbol;
    file.seekg(5, ios::beg);
    symbol = file.get(); // l
    std::cout << symbol << std::endl;
    file.seekg(-4, ios::cur);
    symbol = file.get(); // P
    std::cout << symbol << std::endl;
    file.seekg(-2, ios::end);
    symbol = file.get(); // 2
    std::cout << symbol << std::endl;
    file.seekg(-1, ios::cur);
    symbol = file.get(); // 2
    std::cout << symbol << std::endl;
}