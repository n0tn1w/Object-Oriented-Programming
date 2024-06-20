#include <stdexcept>

#define TT template<class T>
#define UP UniquePtr<T>

TT
class UniquePtr {

public:
    
    UniquePtr(T* data);
    
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr<T>& operator=(const UniquePtr&) = delete;
    
    ~UniquePtr();

    const T& operator*() const;
    T& operator*();

    const T* operator->() const;
    T* operator->();

private:

    void free();

    T* _data = nullptr;

};

TT
UP::UniquePtr(T* data) {
    if(data == nullptr)
        throw std::runtime_error("Why are you doing this frfr!");

    _data = data;
}

TT
void UP::free() {
    delete _data;
}

TT
UP::~UniquePtr() {
    free();
}
TT
const T& UP::operator*() const {
    return *_data;
}
TT
T& UP::operator*() {
    return *_data;
}

TT
const T* UP::operator->() const {
    return _data;
}
TT
T* UP::operator->() {
    return _data;
}