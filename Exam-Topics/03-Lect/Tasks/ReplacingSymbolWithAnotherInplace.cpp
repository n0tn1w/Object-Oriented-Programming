#include <iostream>
#include <fstream>
#include <assert.h>

using std::cout;

namespace Const
{
    const char* FILE_NAME = "file.txt";
} 

// Пример за заместване на символ с друг символ във файл ( четене и писане с fstream)

void SwitchSymbol(std::fstream& fs, char ch1, char ch2) {
    while(!fs.eof()) {
        char curr = fs.get();
        if(curr == ch1) {
            fs.seekg(-1, std::ios::cur);
            fs.put(ch2);
            fs.flush();
        }
    }
}

void SwitchSymbol(const char* fileName, char ch1, char ch2) {
    std::fstream fs(fileName, std::ios::in | std::ios::out);
    assert(fs.is_open());

    SwitchSymbol(fs, ch1, ch2);
    fs.close();
}

int main() {
    SwitchSymbol(Const::FILE_NAME, 'b', 'a');
}

