#pragma once
#include <stdexcept>

#define TT template<class T>
#define SP SharedPtr<T>

struct Counter {

    size_t _sharedCnt = 0;
    size_t _weakCnt = 0;

    void incrementSC() { if(_sharedCnt == 0) { _weakCnt++; } _sharedCnt++; }
    void incrementWC() { _weakCnt++; }

    void decrementSC() { _sharedCnt--; if(_sharedCnt == 0) { _weakCnt--; } }
    void decrementWC() { _weakCnt--; }
};

TT
class SharedPtr {
    
    // The typename is shadowed by the typename of SharedPtr
	template <typename U> friend class WeakPtr;

public:

    SharedPtr() = default; // On every free there should be nullptr checks and on op*

    const T& operator*() const;
    T& operator*();

    // This is really important to be a T*
    const T* operator->() const;
    T* operator->();

    void release();
    bool isInit();

    SharedPtr(T* data);

    SharedPtr(const SharedPtr&);
    SharedPtr(SharedPtr&&);

    SharedPtr<T>& operator=(const SharedPtr&);
    SharedPtr<T>& operator=(SharedPtr&&);

    ~SharedPtr();
private:

    void copyForm(const SharedPtr&);
    void moveFrom(SharedPtr&&);
    void free();

    T* _data = nullptr;
    Counter* _counter;

};

TT
SP::SharedPtr(T* data) {
    if(data == nullptr)
        throw std::runtime_error("E tuka qko grehka");

    _data = data;
    _counter = new Counter();
    _counter->incrementSC();    
}

TT
SP::~SharedPtr() {
    free();
}

TT
SP::SharedPtr(const SharedPtr& oth) {
    copyForm(oth);
}

TT
SP::SharedPtr(SharedPtr&& oth) {
    moveFrom(std::move(oth));
}

TT
SharedPtr<T>& SP::operator=(const SharedPtr& oth) {
    if(this != &oth) {
        copyFrom(oth);
    }

    return *this;
}

TT
SharedPtr<T>& SP::operator=(SharedPtr&& oth) {
    if(this != &oth) {
        moveFrom(std::move(oth));
    }

    return *this;
}

TT
void SP::copyForm(const SharedPtr& oth) {
    _data = oth._data;
    _counter = oth._counter;
    _counter->incrementSC();
}

TT
void SP::moveFrom(SharedPtr&& oth) {
    _data = oth._data;
    _counter = oth._counter;
    
    oth._data = nullptr;
    oth._counter = nullptr;
}

TT
void SP::free() {

    if(!(_data  && _counter))
        return;

    _counter->decrementSC();

    if(_counter->_sharedCnt == 0) {

        _counter->decrementWC();
        if(_counter->_weakCnt == 0) {
            delete _counter;
        }

        delete _data;
    }
}

TT
const T& SP::operator*() const { 
    if(!_data)
        throw std::runtime_error("Pointer bonbok!");
        
    return *_data; 
}
TT
T& SP::operator*() { 
    if(!_data)
        throw std::runtime_error("Pointer bonbok!");

    return *_data; 
}

TT
const T* SP::operator->() const { return _data; }
TT
T* SP::operator->() { return _data; }

TT
void SP::release() {
    free();
}

TT
bool SP::isInit() {
    return _data != nullptr;
}