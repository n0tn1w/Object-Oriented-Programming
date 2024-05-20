#pragma once
#include "MyString.h"

class Writer {

private:
    MyString fileName;
public:
    virtual void write(const int*, size_t) = 0;

};