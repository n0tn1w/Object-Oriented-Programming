#define TT template <class T>
#define UP UniquePtr<T>

#include <iostream>
using namespace std;

TT
class UniquePtr {

public:

    UniquePtr() = delete;
    // UniquePtr(const UniquePtr&);
    // UniquePtr(UniquePtr&&) noexcept;
    // UniquePtr& operator=(const UniquePtr&);
    // UniquePtr& operator=(UniquePtr&&);
    // ~UniquePtr();

    UniquePtr(const T*);
    UniquePtr(T*&&);

    const T& operator*() const;
    T& operator*();
    

private:
    // void copyFrom(const UniquePtr&);
    // void moveFrom(UniquePtr&&);
    // void free();

    T* _ptr;
};

TT
UP::UniquePtr(const T* ptr) : _ptr(ptr) { }

TT
UP::UniquePtr(T*&& ptr) {
    _ptr = std::move(ptr);
    ptr = nullptr;
}

TT
const T& UP::operator*() const {
    return _ptr;
}

TT
T& UP::operator*() {
    return _ptr;
}