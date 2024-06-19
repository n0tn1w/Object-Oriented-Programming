#pragma once
#include <cstddef>
#include <stdexcept>

class StringView {

public:

    StringView(const char*, size_t);

    StringView substr(size_t begin, size_t end);

    size_t GetSize() const;
    
    char operator[](size_t);
    
private:

    const char* _begin;
    size_t _size;

};