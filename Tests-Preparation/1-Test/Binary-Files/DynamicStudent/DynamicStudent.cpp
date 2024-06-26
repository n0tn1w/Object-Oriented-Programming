#include "DynamicStudent.h"

DynamicStudent::DynamicStudent() {
    _name = nullptr;
    _age = 0;
    _fn = 0;
}

DynamicStudent::DynamicStudent(const char* name, int age, int fn) {
    //Validate Name
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    
    if(!(0 < age || age < 100)) {
        return;
    }
    _age = age;

    if(!(0 < fn || fn < 100000)) {
        return;
    }
    _fn = fn;
}

DynamicStudent::DynamicStudent(const DynamicStudent& oth) {
    copyFrom(oth);
}

DynamicStudent& DynamicStudent::operator=(const DynamicStudent& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }
    return *this;
}

void DynamicStudent::copyFrom(const DynamicStudent& oth) {
    _name = new char[strlen(oth._name) + 1];
    strcpy(_name, oth._name);
    _age = oth._age;
    _fn = oth._fn;
}

DynamicStudent::~DynamicStudent() {
    free();
}
void DynamicStudent::free() {
    delete [] _name;
    _name = nullptr;
    _age = 0;
    _fn = 0;
}

std::ofstream& operator<<(std::ofstream& ofs, const DynamicStudent& oth) {
    size_t nameLen = strlen(oth._name);
    ofs.write((const char*) &nameLen, sizeof(nameLen));
    ofs.write((const char*) oth._name, strlen(oth._name));
    ofs.write((const char*) &oth._age, sizeof(oth._age));
    ofs.write((const char*) &oth._fn, sizeof(oth._fn));
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, DynamicStudent& oth) {    
    size_t nameLen = 0;
    ifs.read((char*)&nameLen, sizeof(nameLen));

    oth._name = new char[nameLen + 1];
    ifs.read((char*)oth._name, nameLen);
    ifs.read((char*)&oth._age, sizeof(oth._age));
    ifs.read((char*)&oth._fn, sizeof(oth._fn));

    return ifs;
}

void DynamicStudent::print() const {
    cout << _name << " " << _age << " " << _fn << endl;
}
