#include "DynamicStudent.h"

void writeIntoFile(const DynamicStudent* students, size_t count, std::ofstream& ofs) {
    ofs.write((const char*)&count, sizeof(count));
    for(size_t i = 0; i < count; i++) {
        ofs << students[i];
    }
}

void writeIntoFile(const DynamicStudent* students, size_t count, const char* fileName) {
    std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
    if(!ofs.is_open()) {
        return;
    }

    writeIntoFile(students, count, ofs);
    
    ofs.close();
}

void readFromFile(DynamicStudent*& students, size_t& count, std::ifstream& ifs) {
    ifs.read((char*) &count, sizeof(count));
    students = new DynamicStudent[count];
    
    for(size_t i = 0; i < count; i++) {
        ifs >> students[i];
    }
}

void readFromFile(DynamicStudent*& students, size_t& count, const char* fileName) {
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    if(!ifs.is_open()) {
        return;
    }

    readFromFile(students, count, ifs);

    ifs.close();
}

int main() {
    {
        const char* fileName = "dst.dat";
        size_t count = 5;
        DynamicStudent* students = new DynamicStudent[count]{
            DynamicStudent("Ivan", 10, 123),
            DynamicStudent("Ivanski", 10, 124),
            DynamicStudent("Ivancho", 10, 125),
            DynamicStudent("Ivanov", 10, 126),
            DynamicStudent("Ivanoff", 10, 127)
        };

        writeIntoFile(students, count, fileName);
    }

    {
        const char* fileName = "dst.dat";
        DynamicStudent* students;
        size_t count = 0;
        readFromFile(students, count, fileName);

        for(size_t i = 0; i < count; i++) {
            students[i].print();
        }
    }
}