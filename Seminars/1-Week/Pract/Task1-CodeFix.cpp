#include <iostream>

struct Person
{
    bool isStudent;
    int age;
    short averageGrade;
};

void createPerson(Person& p)
{
    std::cin >> p.isStudent >> p.age >> p.averageGrade;
}

void printStudent(const Person& p)
{
    std::cout << p.isStudent << p.age << p.averageGrade;
}

int main()
{
    Person p;

    createPerson(p);
    printStudent(p);

    Person* personRef = &p;
    std::cout << personRef->age;
}