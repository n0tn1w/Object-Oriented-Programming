#include <iostream>
#include <fstream>
using std::cout;
using std::endl;

namespace Const {
    constexpr const char* FILE_PATH = "file.dat";
}

struct User
{
    char name[25] {};
};

struct Message
{
    User from;
    char* text;
};

// printChat(const char* filePath);
// <from><textSize><textValue>[...];

void printChar(std::ifstream& ifs) {
    Message message;
    ifs.read((char*) message.from.name, 25);

    size_t textSize;
    ifs >> textSize;

    char* content = new char[textSize + 1];
    ifs.read((char*) content, textSize);
}

void printChat(const char* filePath) {
    std::ifstream ifs(filePath, std::ios::in | std::ios::binary);

    if(!ifs.is_open()) {
        return;
    }

    printChar(ifs);
    ifs.close();
}

int main() {
    std::ofstream ofs(Const::FILE_PATH, std::ios::out | std::ios::binary);
    char user[7] = "Ivan";
    size_t cnt = 5;
    char val
    ofs.write((const char*) )

    printChat(Const::FILE_PATH);
}