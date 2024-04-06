// 2. Разпишете голяма четворка на следния клас:

#include <stddef.h>
#include <cstring>

class Student {
	char* _name = nullptr;
	int* _grades = nullptr;
	int _fn;
	size_t _gradesCount;

public:
	Student() = default;

    Student(const char* name, const int* grades, int fn, size_t gradesCount) {
        setName(name);
        setGrades(grades, gradesCount);
        setFn(fn);
    }

    Student(const Student& oth) {
        copyFrom(oth);  
    }

    Student& operator=(const Student& oth) {
        if(this != &oth) {
            free();
            copyFrom(oth);
        }

        return *this;
    }

    ~Student() {
        free();
    }

    void copyFrom(const Student& oth) {
        _gradesCount = oth._gradesCount;
        for(size_t i = 0; i < oth._gradesCount; i++ ) {
            _grades[i] = oth._grades[i];
        }

        _name = new char[strlen(oth._name) + 1];
        strcpy(_name, oth._name);

        _fn = oth._fn;
    }

    void free() {
        _gradesCount = 0;
        delete [] _grades;
        _grades = nullptr;
        _fn = 0;

        delete [] _name;
        _name = nullptr;
    }

    void setName(const char* name) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }

    void setGrades(const int* grades, size_t gradesCount) {
        _gradesCount = gradesCount;
        _grades =  new int[gradesCount];
        for(size_t i = 0; i < gradesCount; i++) {
            _grades[i] = grades[i];
        }
    }

    void setFn(int fn) {
        _fn = fn;
    }

private:
    void free();
    void copyFrom(const Student&);
};

int main() {
    Student s;
    
}