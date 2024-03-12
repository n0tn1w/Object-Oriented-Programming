#include <iostream>
#include <fstream>
#include <assert.h>

using std::cout;

namespace Const
{
    const char* FILE_NAME = "file.txt";
} 

// Пример за функция, която връща големината на файл.


size_t getFileLenght(std::ifstream& ifs) {
    // Трябва да върнем get указателя откъдето сме го взели

    size_t curr = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t len = ifs.tellg();
    ifs.seekg(curr);

    return len;
}

size_t getFileLenght(const char* fileName) {
    std::ifstream ifs(fileName, std::ios::in);

    assert(ifs.is_open());   
    size_t fileLen = getFileLenght(ifs);
    ifs.close();

    return fileLen;
}

int main() {
    cout << getFileLenght(Const::FILE_NAME);
}