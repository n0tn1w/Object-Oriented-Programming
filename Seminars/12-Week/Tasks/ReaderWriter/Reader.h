#pragma once
#include "MyString.h"

class Reader {

public:

    Reader(const MyString&);
    virtual int* read(size_t&) = 0;

private:
    MyString fileName;
};