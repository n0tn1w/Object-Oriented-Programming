#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

#define isLowerCase(ch) ('a' <= ch && ch <= 'z')
#define isCapital(ch) ('A' <= ch && ch <= 'Z')

// Пример за клас Person с име (низ с дължина най-много 20 символа) и години [5...90].

namespace Const
{
    constexpr size_t PERSON_NAME_LENGHT = 20;

    constexpr size_t MIN_AGE = 5;
    constexpr size_t MAX_AGE = 90;

    constexpr size_t MIN_NAME_LENGHT = 2;
    constexpr size_t MAX_NAME_LENGHT = 20;
}

namespace Helper 
{
    inline bool isFirstLetterCapital(const char* name) {
        return isCapital(name[0]);
    }

    inline bool areAllLetterLowerCase(const char* name) {
        size_t len = strlen(name);

        for(size_t i = 0; i < len; i++) {
            if(!isLowerCase(name[i])) {
                return false;
            }
        }

        return true;
    }
}


class Person
{
    char _name[Const::PERSON_NAME_LENGHT + 1] = "No name";
    int _age = -1;

public:
    Person() = default;

    Person(const char* name, int age) {
        setName(name);
        setAge(age);
    }

    const char* getName() const {
        return this->_name;
    }

    int getAge() const {
        return this->_age;
    }

    void setAge(int age) {
        if(!isAgeValid(age)) {
            return;
        }
        this->_age = age;
    }

    void setName(const char* name) {
        if(!isNameValid(name)) {
            return ;
        }
        strcpy(this->_name, name);
    }

private:

    bool isNameValid(const char* name) const {
        size_t len = strlen(name);

        if(!(Const::MIN_NAME_LENGHT <= len && len <= Const::MAX_NAME_LENGHT)) {
            // Len is not correct
            return false;
        } else if(!Helper::isFirstLetterCapital(name)) {
            // First letter is not capital
            return false;            
        } else if(!Helper::areAllLetterLowerCase(name + 1)) {
            // There are atleast not small letter in the name excluding the first one
            return false;
        } else {
            return true;
        }
    }

    bool isAgeValid(int age) const{
        return Const::MIN_AGE <= age && Const::MAX_AGE >= age;
    }
};

int main() {
    Person p;
    cout << p.getName() << " " << p.getAge() << endl;
    Person p2("Ivan", 33);
    cout << p2.getName() << " " << p2.getAge() << endl;
    Person p3("Ivan", 2);
    cout << p3.getName() << " " << p3.getAge() << endl;
    Person p4("Morethatntwentysymbos", 2);
    cout << p4.getName() << " " << p4.getAge() << endl;
    Person p5("Lessthatntwentysymbo", 2);
    cout << p5.getName() << " " << p5.getAge() << endl;
}
