#pragma once
#include "Reader.h"

class ReaderBinary : public Reader {

public:
    ReaderBinary(const MyString&);
    int* read(size_t&) override;
};