#pragma once

#include <stddef.h>
#include <cstring>
#include <stdexcept>
#include <utility>

class StringPool {

public:

    StringPool();

    const char* getAllocatedString(const char*);
    void releaseString(const char*);

    StringPool(const StringPool&) = delete;
    StringPool& operator=(const StringPool&) = delete;

    ~StringPool();

private:
    struct StoredString {
        char* _str = nullptr;
        int _refCount = 0;
    };

    void resize();
    size_t add(const char*);
    void deleteAt(size_t);

    int findString(const char*);
    
    StoredString* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

};