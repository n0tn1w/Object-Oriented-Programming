#include "Professor.h"

Professor::Professor() : Person() {
    _subjects = nullptr;
}

Professor::Professor(const char* name, unsigned age, const char* const* subjects, size_t countSubjects) : Person(name, age) {
    setSubjects(subjects, countSubjects);
}

Professor::Professor(const Professor& oth) : Person(oth) {
    copyFrom(oth);
}

Professor& Professor::operator=(const Professor& oth) {
    if(this != &oth) {
        free();
        Person::operator=(oth);
        copyFrom(oth);
    }
    return *this;
}

Professor::~Professor() {
    free();
}

Professor::Professor(Professor&& oth) : Person(std::move(oth)) {
    moveFrom(std::move(oth));
}

Professor& Professor::operator=(Professor&& oth) {
    if(this != &oth) {
        free();
        Person::operator=(std::move(oth));
        moveFrom(std::move(oth));
    }
    return *this;
}

void Professor::copyFrom(const Professor& oth) {
    copyStringArray(_subjects, oth._subjects, oth._countSubjects);
    _countSubjects = oth._countSubjects;
}

void Professor::moveFrom(Professor&& oth) {
    _subjects = oth._subjects;
    _countSubjects = oth._countSubjects;

    oth._subjects = nullptr;
    oth._countSubjects = 0;
}

void Professor::free() {
    for(size_t i = 0; i < _countSubjects; i++) {
        delete[] _subjects[i];
    }
    delete[] _subjects;
}


void static copyStringArray(char** dest, const char* const* source, size_t countSubjects) {
    char** dest = new char*[countSubjects];

    for(size_t i = 0; i < countSubjects; i++) {
        dest[i] = new char[strlen(source[i])];
        strcpy(dest[i], source[i]);
    }
}

void Professor::setSubjects(const char* const* subjects, size_t countSubjects) {
    copyStringArray(_subjects, subjects, countSubjects);
}
 

char** Professor::getSubjects() const {
    return _subjects;
}
