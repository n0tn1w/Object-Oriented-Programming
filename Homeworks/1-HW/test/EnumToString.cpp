#include <iostream>

// Define your enum class
enum class MyEnum {
    Value1,
    Value2,
    Value3
};

int main() {
    // Convert enum value to its underlying integer type and print it
    size_t colCount;
        std::cin >> colCount;

    char data[colCount][200];
    for(int i =0;i<colCount;i++) {
        char buffer[200];
        std::cin >> data[i];
    }
    return 0;
}