#pragma once
#include "Reader.h"

class ReaderArr : public Reader {

public:
    ReaderArr(const MyString&);
    int* read(size_t&) override;
};