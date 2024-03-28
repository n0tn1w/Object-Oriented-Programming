#include "GraduatedStudent.h"
#include <cstring>
#include <iostream>

GraduatedStudent::GraduatedStudent() {
    std::cout << "Def C" << std::endl;
}

GraduatedStudent::GraduatedStudent(const char* name, const int* grades, size_t gradesCount, const char* quote) {
    setName(name);
    setGrades(grades, gradesCount);
    setQuote(quote);
}

GraduatedStudent::GraduatedStudent(const GraduatedStudent& oth) {
    std::cout << "CC" << std::endl;
    copyFrom(oth);
}

GraduatedStudent& GraduatedStudent::operator=(const GraduatedStudent& oth) {
    if(this != &oth) {
        std::cout << "OP =" << std::endl;

        free();
        copyFrom(oth);
    }

    return *this;
}

GraduatedStudent::~GraduatedStudent() {
    std::cout << "Dest" << std::endl;
    free();
}

void GraduatedStudent::copyFrom(const GraduatedStudent& oth) {
    this->_name = new char[strlen(oth._name) + 1];
    strcpy(this->_name, oth._name);

    this->_gradesCount = oth._gradesCount;
    this->_grades = new int[oth._gradesCount];

    // Normal way
    for(size_t i = 0; i < oth._gradesCount; i++) {
        this->_grades[i] = oth._grades[i];
    } 
    // std::memcpy
    // std::memcpy(this->_grades, oth._grades, sizeof(oth._grades));

    strcpy(this->_quote, oth._quote);
}

void GraduatedStudent::free() {
    this->_gradesCount = 0;

    delete [] this->_name;
    delete [] this->_grades;

    this->_name = nullptr;
    this->_grades = nullptr;
}

const char* GraduatedStudent::getName() const {
    return this->_name;
}

const int* GraduatedStudent::getGrades() const {
    return this->_grades;
}

size_t GraduatedStudent::getGradesCount() const {
    return this->_gradesCount;
}


const char* GraduatedStudent::getQuote() const {
    return this->_quote;
}

void GraduatedStudent::setName(const char* name) {

    if(!name && this->_name ==  name) {

        // Both are pointing to the same address
        return;

    } else {

        delete [] this->_name;

        size_t len = strlen(name);
        this->_name = new char[len + 1]; 
        strcpy(this->_name, name);

    }
}

void GraduatedStudent::setGrades(const int* grades, size_t gradesCount) {

    if(!grades || this->_grades == grades) {
        // grades is nullptr or point to the same resource as the _grades
        return;

    } else {

        delete [] this->_grades;

        this->_gradesCount = gradesCount;
        this->_grades = new int[gradesCount];
        for(size_t i = 0; i < gradesCount; i++) {
            if(!(2 <= grades[i] && grades[i] <= 6)) {
                // The grade is invalid and will be set to -1
                this->_grades[i] = -1;
            } else {
                this->_grades[i] = grades[i];
            }
        }
    }
}

void GraduatedStudent::setQuote(const char* quote) {

    if(!quote) {
        // quote is nullptr
        return;

    }else {
        size_t len = strlen(quote);
        
        if(len > Const::MAX_QUOTE_LEN) {
            // Quote is too big
            return;
        } else {
            strcpy(this->_quote, quote);
        }
    }
}