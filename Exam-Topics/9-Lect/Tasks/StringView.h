#pragma once
#include <cstring>
#include <fstream>
#include "MyString.h"

class StringView {

public:

    StringView(const char*, int);
    StringView(const char*);
    StringView(const MyString&);

    StringView substr(unsigned, int) const;
    char operator[](unsigned) const;
    unsigned size() const;

    friend std::ostream& operator<<(std::ostream&, const StringView&);

private:

    const char* _begin;
    int _offset;

};