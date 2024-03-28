#pragma once
#include <cstddef>

namespace Const {
    constexpr size_t MAX_QUOTE_LEN = 30;
};

class GraduatedStudent {

    char* _name = nullptr;
    int* _grades = nullptr;
    size_t _gradesCount = 0;
    char _quote[Const::MAX_QUOTE_LEN + 1]; // for the \0

public:

    //GraduatedStudent() = default; // Should be this but i have couts in the Big 4
    GraduatedStudent();
    GraduatedStudent(const char*, const int*, size_t, const char*);
    GraduatedStudent(const GraduatedStudent&);
    GraduatedStudent& operator=(const GraduatedStudent&);
    ~GraduatedStudent();

    const char* getName() const;
    const int* getGrades() const;
    size_t getGradesCount() const;
    const char* getQuote() const;

    void setName(const char*);
    void setGrades(const int*, size_t);
    void setQuote(const char*);

private:

    void copyFrom(const GraduatedStudent&);
    void free();

};