#pragma once
#include <utility> 
#include <cstring>
#include <fstream>
#include <iostream>
class StringView;

class MyString {

public:

    MyString();
    MyString(const char*);
    MyString(const MyString&);
    MyString& operator=(const MyString&);
    ~MyString();

    MyString(MyString&&) noexcept;
    MyString& operator=(MyString&&) noexcept;

    const char* c_str() const;

    const char& operator[](unsigned index) const;
    char& operator[](unsigned index);

    const char& at(unsigned index) const;
    char& at(unsigned index);

    void push_back(const char);
    void append(const MyString&);

    void clear();
    unsigned length() const;
    unsigned capacity() const;

    int compare(const MyString&);
    bool empty() const;

    friend std::ostream& operator<<(std::ostream& ,const MyString& oth);
    friend std::istream& operator>>(std::istream&, MyString& oth);

    MyString& operator+=(const MyString&);

    friend MyString operator+(const MyString&, const MyString &);

    StringView substr(unsigned, int) const;
private:

    void copyFrom(const MyString&);
    void moveFrom(MyString&&) noexcept;
    void free();

    void resize(unsigned newSize);

    explicit MyString(unsigned);
private:

    char* _data = nullptr;
    unsigned _capacity = 0, _size = 0;

};