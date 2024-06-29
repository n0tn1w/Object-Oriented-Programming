#include "StringPool.h"

StringPool::StringPool() {
    _capacity = 4;
    _data = new StoredString[_capacity];
}

const char* StringPool::getAllocatedString(const char* str) {
    int index = findString(str);

    if(index == -1) {
        // No such string exist
        // It needs to be added to the pool

        size_t index = add(str);

        return _data[index]._str;
    } else {
        // It exist and needs to be removed

        _data[index]._refCount++;
        return _data[index]._str;
    }
}

void StringPool::releaseString(const char* str) {
    int index = findString(str);

    if(index == -1) {
        // Idiot

        throw std::runtime_error("Cannot release");
    } else {

        --_data[index]._refCount;
        if(_data[index]._refCount == 0) {
            deleteAt(index);
        }
    }
}

void StringPool::deleteAt(size_t idx) {
    delete[] _data[idx]._str;
    _data[idx]._str = nullptr;
    _data[idx]._refCount = 0;

    std::swap(_data[idx], _data[_size - 1]);
    _size--;
}



int StringPool::findString(const char* str) {
    for(size_t i = 0; i < _size; i++) {
        if(strcmp(_data[i]._str, str) == 0) {
            return i;
        }
    }

    return -1;
}

size_t StringPool::add(const char* str) {
    if(_size == _capacity)
        resize();

    size_t len = strlen(str);
    _data[_size]._str = new char[len];
    strcpy(_data[_size]._str, str);
    _data[_size]._refCount = 1;

    return _size++;
}

void StringPool::resize() {
    _capacity *= 2;
    StoredString* newData = new StoredString[_capacity];

    for(size_t i = 0; i <_size; i++) {
        newData[i] = _data[i];
    }

    delete[] _data;
    _data = newData;
}

StringPool::~StringPool() {
    for(size_t i = 0; i < _size; i++) {
        delete[] _data[i]._str;
    }

    delete[] _data;
}