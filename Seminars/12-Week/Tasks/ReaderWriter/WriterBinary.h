#pragma once
#include "Writer.h"
#include "MyString.h"

class WriterBinary : public Writer {
    
public:
    WriterBinary(const MyString&);
    void write(const int*, size_t) override;
};