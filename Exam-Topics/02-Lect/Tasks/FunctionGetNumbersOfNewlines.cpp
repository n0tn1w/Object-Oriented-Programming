#include <iostream>
#include <fstream>
#include <assert.h>

using std::cout;

namespace Const
{
  const char* FILE_NAME = "file.txt";
}
 
//Пример за функция, която връща брой редове в текстов файл.

size_t GetNumberOfSymbol(std::ifstream& ifs, char ch) {
    size_t count = 0;

    while(!ifs.eof()) {
        char curr = ifs.get();

        if(curr == ch) {
            count++;
        }
    }

    return count;
}

size_t GetNumberOfSymbol(const char* fileName, char ch) {
    std::ifstream ifs(fileName, std::ios::in);

    assert(ifs.is_open());
    size_t count = GetNumberOfSymbol(ifs,ch);
    ifs.close();

    return count;
}

size_t GetNumberOfNewLines(const char* fileName) {
    return GetNumberOfSymbol(fileName, '\n') + 1;
}

int main() {
    cout << GetNumberOfNewLines(Const::FILE_NAME);
}