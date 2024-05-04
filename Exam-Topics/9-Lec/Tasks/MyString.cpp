#include "MyString.h"

namespace MyStringConsts {
    constexpr char INDEX_OUT_OF_RANGE[] = "Index out of range!";
}

MyString::MyString() {
    _capacity = 1;
    _size = 0;
    _data = new char[_capacity];
    _data[0] = '\0';
}

MyString::MyString(const char* data) {
    _size = strlen(data);
    _capacity = _size + 1;
    _data = new char[_capacity];
    strcpy(_data, data);
    _data[_size] = '\0';
}

MyString::MyString(const MyString& oth) {
    copyFrom(oth);
}

MyString& MyString::operator=(const MyString& oth) {

    if(this != &oth) {
        free();
        copyFrom(oth);
    }

    return *this;
}

MyString::~MyString() {
    free();
}

MyString::MyString(MyString&& oth) noexcept{
    moveFrom(std::move(oth));
}

MyString& MyString::operator=(MyString&& oth) noexcept{

    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }

    return *this;
}

void MyString::copyFrom(const MyString& oth) {

    // abc\0
    _size = oth._size;
    _capacity = oth._capacity;
    _data = new char[_capacity];
    strcpy(_data, oth._data);
    _data[_size] = '\0';
}

void MyString::moveFrom(MyString&& oth) noexcept {
    _size = oth._size;
    _capacity = oth._capacity;
    _data = oth._data;

    oth._size = 0;
    oth._capacity = 0;
    oth._data = nullptr;
}

void MyString::free() {
    _size = 0;
    _capacity = 0;
    delete[] _data;
}

const char* MyString::c_str() const {
    return _data;
}

const char& MyString::operator[](unsigned index) const {
    return _data[index];
}

char& MyString::operator[](unsigned index) {
    return _data[index];
}

const char& MyString::at(unsigned index) const {

    if(index >= _size) {
        throw std::out_of_range(MyStringConsts::INDEX_OUT_OF_RANGE);
    }
    return _data[index];   
}

char& MyString::at(unsigned index) {

    if(index >= _size) {
        throw std::out_of_range(MyStringConsts::INDEX_OUT_OF_RANGE);
    }
    return _data[index];   
}

void MyString::resize(unsigned newCapacity) {

    unsigned capacityTimesTwo = _capacity * 2;
    if(newCapacity > capacityTimesTwo) {
        _capacity = newCapacity * 2;
    } else {
        _capacity *= 2;
    }

    char* newData = new char[_capacity];
    strcpy(newData, _data);
    newData[_size] = '\0';

    _data = newData;
}

void MyString::push_back(const char ch) {
    
    unsigned newCapacity = _capacity + 1;
    if(newCapacity > _capacity)
        resize(newCapacity);

    _data[_size] = ch;
    _size++;
    _data[_size] = '\0';
}

void MyString::append(const MyString& oth) {

    unsigned newCapacity = _capacity + oth._capacity - 1;
    if(newCapacity > _capacity)
        resize(newCapacity);

    strcpy(_data + _size, oth._data);
    _data[_size + oth._size - 1] = '\0';
}

void MyString::clear() {
    free();
    _capacity = 1;
    _size = 0;
    _data = new char[1];
    _data[0] = '\0';
}
unsigned MyString::length() const {
    return _size;
}

unsigned MyString::capacity() const {
    return _capacity;
}

int MyString::compare(const MyString& oth) 
{
    return strcmp(_data, oth._data);
}

bool MyString::empty() const {
    return _size > 0;
}

std::ostream& operator<<(std::ostream& os,const MyString& oth) {
    return os << oth._data;
}

std::istream& operator>>(std::istream& is, MyString& oth) {
    oth.free();

    char buff[1024];
    is.getline(buff, 1024);
    unsigned buffLen = strlen(buff);

    oth._size = buffLen;
    oth._capacity = buffLen + 1;
    oth._data = new char[oth._capacity];
    strncpy(oth._data, buff, buffLen);
    oth._data[buffLen] = '\0';

    return is;
}

MyString& MyString::operator+=(const MyString& oth) {
    append(oth);

    return *this;
}

MyString::MyString(unsigned capacity) {
    _capacity = capacity;
    _size = 0;
    _data = new char [_capacity];
    _data[0] = '\0';
}


MyString operator+(const MyString& l, const MyString & r) {
    MyString str(l.length() + r.length());
    str += l;
    str += r;

    return str;
}
