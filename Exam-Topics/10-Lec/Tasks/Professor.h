#pragma once
#include "Person.h"

class Professor : public Person {

public:

    Professor();
    Professor(const char*, unsigned, const char* const*, size_t);
    Professor(const Professor&);
    Professor& operator=(const Professor&);
    ~Professor();

    Professor(Professor&&);
    Professor& operator=(Professor&&);

    char** getSubjects() const;
    
private:
    void copyFrom(const Professor&);
    void moveFrom(Professor&&);
    void free();

    void setSubjects(const char* const*, size_t);

    char** _subjects;
    size_t _countSubjects;

};