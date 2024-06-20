#pragma once
#include "SharedPtr.hpp"
#include <iostream>

#define TT template<class T>
#define WP WeakPtr<T>

TT
class WeakPtr {

public:

    // For me i would make it deleted
    WeakPtr() = default; // On every free there should be nullptr checks and on op*

    WeakPtr(const SharedPtr<T>& oth);

    const T& operator*() const;
    T& operator*();
    const T* operator->() const;
    T* operator->();

    WeakPtr(const WeakPtr&);
    WeakPtr(WeakPtr&&);
    WeakPtr<T> operator=(const WeakPtr&);
    WeakPtr<T> operator=(WeakPtr&&);
    ~WeakPtr();

    // does it have valid value insdie of it 
    bool expired() const;

    // Work as promotion 
    // expired() ? shared_ptr<T>() : shared_ptr<T>(*this
    SharedPtr<T> lock() const;

private:

    void copyForm(const WeakPtr&);
    void moveFrom(WeakPtr&&);
    void free();

    T* _data = nullptr;

    Counter* _counter = nullptr;
};

TT
const T& WP::operator*() const { 
    if(!_data)
        throw std::runtime_error("Pointer bonbok!");

    return *_data; 
}
TT
T& WP::operator*() { 
    if(!_data)
        throw std::runtime_error("Pointer bonbok!");
    return *_data; 
}
TT
const T* WP::operator->() const { return _data; }
TT
T* WP::operator->() { return _data; }

TT
WP::WeakPtr(const SharedPtr<T>& oth) {
    _data = oth._data;
    _counter = oth._counter;
    _counter->incrementWC();
}

TT
void WP::copyForm(const WeakPtr& oth) {
    _data = oth._data;
    _counter = oth._counter;
    _counter->incrementWC();    
}

TT
void WP::moveFrom(WeakPtr&& oth) {
    _data = oth._data;
    _counter = oth._counter;
    oth._data = nullptr;
    oth._counter= nullptr;
}

TT
void WP::free() {

    if(!(_data && _counter))
        return;

    _counter->decrementWC();
    if(_counter->_weakCnt == 0) {
        delete _counter;
    }
}

TT
WP::WeakPtr(const WeakPtr& oth) { copyForm(oth); }
TT
WP::WeakPtr(WeakPtr&& oth) { moveFrom(std::move(oth)); }
TT
WeakPtr<T> WP::operator=(const WeakPtr& oth) {
    if(this != &oth) {
        copyForm(oth);
    }
    return *this;
}
TT
WeakPtr<T> WP::operator=(WeakPtr&& oth) {
    if(this != &oth) {
        moveFrom(std::move(oth));
    }
    return *this;
}
TT
WP::~WeakPtr() { free(); }

TT
bool WP::expired() const {
    return _counter && _counter->_sharedCnt == 0;
}

TT
SharedPtr<T> WP::lock() const {
    if(expired())
        return SharedPtr<T>();
    else    
        return SharedPtr<T>(_data);
}
