#pragma once
#include "Writer.h"
#include "MyString.h"

class WriterArr : public Writer {
    
public:
    WriterArr(const MyString&);
    void write(const int*, size_t) override;
};