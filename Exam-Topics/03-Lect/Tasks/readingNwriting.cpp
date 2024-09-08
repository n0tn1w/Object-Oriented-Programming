#include <fstream>
#include <cstring>
#include <iostream>
using std::cout;

struct Obj {
    int n = 1;
    char ch = 'a';
};

struct ObjDynamic {
    unsigned nameLen;
    char* name;
};

void setObjDynamic( ObjDynamic& objDyn, unsigned nameLen, const char* str) {
    objDyn.nameLen = nameLen;
    objDyn.name = new char[objDyn.nameLen];
    strcpy(objDyn.name, str);
}

// Obj arrStatic[10];

// Obj* arrDynamic = new Obj[<value_saved_in_file>];

void writeObject() {
    std::ofstream ofs("object.dat", std::ios::binary);
    Obj obj {1, 'a'};
    ofs.write((const char*)&obj, sizeof(obj));
}

void writeDynamicObjecy() {
    std::ofstream ofs("dynamicObject.dat", std::ios::binary);
    ObjDynamic objDyn;

    setObjDynamic(objDyn, 4, "abcd");

    ofs.write((const char*)&objDyn.nameLen, sizeof(objDyn.nameLen));
    ofs.write((const char*) objDyn.name, objDyn.nameLen);
}

void writeStaticArray() {
    std::ofstream ofs("staticArray.dat", std::ios::binary);
    Obj staticArray[10];
    ofs.write((const char*) &staticArray, sizeof(staticArray));
}

void writeArrayWithDynamicElts() {
    std::ofstream ofs("arrayWithDynamicElts.dat", std::ios::binary);

    unsigned n = 2;
    ObjDynamic* dynArray = new ObjDynamic[n];
    setObjDynamic(dynArray[0], 4, "abcd");
    setObjDynamic(dynArray[1], 3, "efg");

    ofs.write((const char*)&n, sizeof(n));
    for(unsigned i = 0; i < n; i++) {
        ofs.write((const char*)&dynArray[i].nameLen, sizeof(dynArray[i].nameLen));
        ofs.write((const char*) dynArray[i].name, dynArray[i].nameLen);
    }

}

void readObject() {
    std::ifstream ifs("object.dat", std::ios::binary);
    Obj obj;
    ifs.read((char*)&obj, sizeof(Obj));
}


void readDynamicObjecy() {
    std::ifstream ifs("dynamicObject.dat", std::ios::binary);
    ObjDynamic objDyn;
    ifs.read((char*)&objDyn.nameLen, sizeof(objDyn.nameLen));
    objDyn.name = new char[objDyn.nameLen + 1];
    ifs.read((char*) objDyn.name, objDyn.nameLen);
}

unsigned getFileSize(std::ifstream& ifs) {
    unsigned curr = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    unsigned len = ifs.tellg();
    ifs.seekg(curr);

    return len - curr;
}

void readStaticArray() {
    std::ifstream ifs("staticArray.dat", std::ios::binary);

    unsigned fileSize = getFileSize(ifs);

    Obj* dynArray = new Obj[fileSize / sizeof(Obj)];
    ifs.read((char*) dynArray, fileSize);
}

void readArrayWithDynamicElts() {
    std::ifstream ifs("arrayWithDynamicElts.dat", std::ios::binary);

    unsigned n = 0;
    ifs.read((char*)&n, sizeof(n));
    ObjDynamic* dynArray = new ObjDynamic[n];

    for(unsigned i = 0; i < n; i++) {
        ifs.read((char*)&dynArray[i].nameLen, sizeof(dynArray[i].nameLen));
        dynArray[i].name = new char[dynArray[i].nameLen + 1];
        ifs.read((char*) dynArray[i].name, dynArray[i].nameLen);
    }

    // for(unsigned i = 0; i < n; i++) {
    //     cout << dynArray[i].nameLen << dynArray[i].name;
    // }
}

int main () {
    writeObject();
    readObject();

    writeDynamicObjecy(); 
    readDynamicObjecy();

    writeStaticArray();
    readStaticArray();

    writeArrayWithDynamicElts(); 
    readArrayWithDynamicElts();
}