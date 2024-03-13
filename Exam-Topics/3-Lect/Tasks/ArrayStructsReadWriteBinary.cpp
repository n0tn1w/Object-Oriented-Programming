#include <iostream>
#include <fstream>
#include <assert.h>

using std::cout;
using std::cin;

namespace Const
{
    const char* FILE_NAME = "file.dat";
    const size_t NAME_SIZE = 15;
}

// Пример за запазване/четене на масив от обекти(от един тип) във файл.

struct Student
{
    char name[Const::NAME_SIZE];
    int age;
    double height;
};

void WriteStudentIntoFile(std::ofstream& ofs, const Student& st) {
    ofs.write((const char*)&st, sizeof(Student));
}

void WriteIntoFile(std::ofstream& ofs, const Student* students, size_t count) {
    for(size_t i = 0; i < count; i++) {
        WriteStudentIntoFile(ofs, students[i]);
    }
}

void WriteIntoFile(const char* fileName, const Student* students, size_t count) {
    std::ofstream ofs(fileName, std::ios::out | std::ios::binary);

    assert(ofs.is_open());

    WriteIntoFile(ofs, students, count);

    ofs.close();
}

size_t GetFileSize(std::ifstream& ifs) {
    size_t curr = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t len = ifs.tellg();
    ifs.seekg(curr);

    return len;
}

void ReadFromFile(std::ifstream& ifs, Student*& students) {
    size_t fileSize = GetFileSize(ifs);
    students = new Student[fileSize / sizeof(Student)];
    ifs.read((char*)students, fileSize);
}

void ReadFromFile(const char* fileName, Student*& students) {
    std::ifstream ifs(fileName, std::ios::in);

    assert(ifs.is_open());

    ReadFromFile(ifs, students);
    ifs.close();
}

void PrintStudent(const Student& student) {
    std::cout << student.name << " " << student.age << " " << student.height << std::endl;
}

void PrintAllStudents(const Student* stds, size_t count) {
    for(size_t i = 0; i < count; i++) {
        PrintStudent(stds[i]);
    }
}

int main() {
    Student stds[2] = {{"Ivan", 18, 1.67},{"Peter", 20,1.87} };
    WriteIntoFile(Const::FILE_NAME, stds, 2);
    Student* students = new Student;
    ReadFromFile(Const::FILE_NAME, students);
    PrintAllStudents(students, 2);
}