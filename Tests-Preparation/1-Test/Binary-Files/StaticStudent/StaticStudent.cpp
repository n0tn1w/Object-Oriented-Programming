#include <iostream>
#include <fstream>
#include <cstring>
#include <stddef.h>
using std::cout;
using std::cin;
using std::endl;

namespace Const{
    constexpr size_t MAX_NAME_LENGHT = 22;
};

namespace Helper {
    bool isLetterCapital(char ch) {
        return 'A' <= ch && ch <= 'Z';
    }
    bool isLetterLower(char ch) {
        return 'a' <= ch && ch <= 'z';
    }

    bool allLettersLowerCase(const char* str) {
        while(*str) {
            if(!isLetterLower(*str)) {
                return false;
            }
            ++str;
        }
        return true;
    }

    bool isValidName(const char* name) {
        if(!isLetterCapital(*name)) {
            return false;
        }

        if(!allLettersLowerCase(++name)) {
            return false;
        }

        return true;
    }

    size_t getFileSize(std::ifstream& ifs) {
        size_t curr = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        size_t len = ifs.tellg();
        ifs.seekg(curr);

        return len;
    }
};

struct StaticStudent {
    char _name[Const::MAX_NAME_LENGHT + 1];
    bool _isMale;
    int _age;

    void print() const {
        cout << _name << " " << _isMale << " " << _age << endl;
    }
};

StaticStudent initStudent(const char* name, bool isMale, int age) {
    StaticStudent ss;
    if(!Helper::isValidName(name)) {
        return {};
    }
    std::strcpy(ss._name, name);
    ss._isMale = isMale;

    if(age < 0 || age > 100) {
        return {};
    }
    ss._age = age;

    return ss;
}

void writeStudentIntoFile(const StaticStudent& ss, std::ofstream& ofs) {
    ofs.write((const char*)&ss, sizeof(StaticStudent));
}

void writeIntoFile(const StaticStudent* ss, size_t count, std::ofstream& ofs) {
    for(size_t i = 0; i < count; i++) {
        writeStudentIntoFile(ss[i], ofs);
    }
}

void writeIntoFile(const StaticStudent* ss, size_t count, const char* fileName) {
    std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
    if(!ofs.is_open()) {
        return;
    }
    writeIntoFile(ss, count, ofs);

    ofs.close();
}

size_t readFromFile(StaticStudent*& ss, std::ifstream& ifs) {
    size_t fileSize = Helper::getFileSize(ifs);
    size_t count = fileSize / sizeof(StaticStudent);

    ss = new StaticStudent[count];
    ifs.read((char*)ss, sizeof(StaticStudent) * count);
    return count;
}

size_t readFromFile(StaticStudent*& ss, const char* fileName) {
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    if(!ifs.is_open()) {
        return 0;
    }

    size_t count = readFromFile(ss, ifs);

    ifs.close();
    return count;
}

int main() {
    {
        const char* fileName = "std.dat";
        size_t count = 5;
        StaticStudent* students = new StaticStudent[5];
        students[0] = initStudent("Ivan", true, 12);
        students[1] = initStudent("Ivanski", true, 12);
        students[2] = initStudent("Ivancho", true, 12);
        students[3] = initStudent("Ivanov", true, 12);
        students[4] = initStudent("Ivanoff", false, 21);

        writeIntoFile(students, count, fileName);
    }

    {
        const char* fileName = "std.dat";
        StaticStudent* ss;
        size_t len = readFromFile(ss, fileName);

        for(size_t i = 0; i < len; i++) {
            ss[i].print();
        }
        cout << endl;
    }
}