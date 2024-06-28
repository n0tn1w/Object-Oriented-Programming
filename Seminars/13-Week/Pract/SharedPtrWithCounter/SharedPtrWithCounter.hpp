#include <stddef.h>
#include <iostream>

#define TT template<typename T, int N>
#define SPC SharedPtrWithCounter<T,N>

TT
class SharedPtrWithCounter {

public:

    SharedPtrWithCounter(T*);
    SharedPtrWithCounter(const SharedPtrWithCounter&);
    SharedPtrWithCounter(SharedPtrWithCounter&&);
    SharedPtrWithCounter<T,N>& operator=(const SharedPtrWithCounter&);
    SharedPtrWithCounter<T,N>& operator=(SharedPtrWithCounter&&);
    ~SharedPtrWithCounter();

    operator bool() const;

    const T& operator*() const;
    T& operator*();

    const T* operator->() const;
    T* operator->();

private:

    void copyFrom(const SharedPtrWithCounter&);
    void moveFrom(SharedPtrWithCounter&&);
    void free();

    T* _data;
    int* _counter;
};

TT
SPC::SharedPtrWithCounter(T* data) {
    _counter = new int(1);
    _data = data;
}

TT
SPC::operator bool() const {
    return _data != nullptr;
}

TT
SPC::SharedPtrWithCounter(const SharedPtrWithCounter& oth) {
    copyFrom(oth);
} 

TT
SPC::SharedPtrWithCounter(SharedPtrWithCounter&& oth) {
    moveFrom(std::move(oth));
}

TT
SharedPtrWithCounter<T,N>& SPC::operator=(const SharedPtrWithCounter& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }

    return *this;
} 

TT
SharedPtrWithCounter<T,N>& SPC::operator=(SharedPtrWithCounter&& oth) {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }

    return *this;
}

TT
SPC::~SharedPtrWithCounter() {
    free();
}

TT
void SPC::free() {
    if (*_counter == 1) {
        delete _counter;
        delete _data;
    }

    *_counter--;
}

TT
void SPC::copyFrom(const SharedPtrWithCounter& oth) {

    if(*oth._counter >= N) {
        throw std::runtime_error("Kakvo pravim sega?");
        return;
    }

    (*(oth._counter))++;
    _data = oth._data;
    _counter = oth._counter;
}

TT
void SPC::moveFrom(SharedPtrWithCounter&& oth) {
    _data = oth._data;
    _counter = oth._counter;

    oth._data = nullptr;
    oth._counter = nullptr;
}

TT
const T& SPC::operator*() const {
    return *_data;
}

TT
T& SPC::operator*() {
    return *_data;
}

TT
const T* SPC::operator->() const {
    return *_data;
}

TT
T* SPC::operator->() {
    return *_data;
}