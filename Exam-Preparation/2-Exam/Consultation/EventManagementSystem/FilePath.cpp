#include "FilePath.h"
#include <cstring>
#include <utility>

FilePath::FilePath(const char* str) {
    size_t len = strlen(str);
    _name = new char[len + 1];
    strcpy(_name, str);
}

FilePath::FilePath(const FilePath& oth) {
    copyFrom(oth);
}
FilePath::FilePath(FilePath&& oth) {
    moveFrom(std::move(oth));
}
FilePath& FilePath::operator=(const FilePath& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }
    return *this;
}
FilePath& FilePath::operator=(FilePath&& oth) {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }
    return *this;
}
FilePath::~FilePath() {
    free();
}

void FilePath::copyFrom(const FilePath& oth) {
    size_t len = strlen(oth._name);
    _name = new char[len + 1];
    strcpy(_name, oth._name);
}

void FilePath::moveFrom(FilePath&& oth) {
    _name = oth._name;
    oth._name = nullptr;
}

void FilePath::free() {
    delete[] _name;
}