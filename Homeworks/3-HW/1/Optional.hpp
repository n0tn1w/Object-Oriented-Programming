#include <utility>

template <class T>
class Optional {

public:
    Optional() = default;
    Optional(T*);

    Optional(const Optional<T>&);
    Optional(Optional<T>&&);
    Optional<T>& operator=(const Optional<T>&);
    Optional<T>& operator=(Optional<T>&&);
    ~Optional();

    const T& operator*() const;
    T& operator*();

    const T& operator->() const;
    T& operator->();

    void reset();
    bool has_value() const;

private:
    void copyFrom(const Optional<T>&);
    void moveFrom(Optional<T>&&);
    void free();

    T* _data = nullptr;
};

template <class T>
Optional<T>::Optional(T* ptr) {
    if(ptr) 
        _data = new T(*ptr);
}

template <class T>
void Optional<T>::copyFrom(const Optional<T>& oth) {
    if(oth.has_value) {
        _data = new T(*oth._data);
    } else {
        _data = nullptr;
    }
}
template <class T>
void Optional<T>::moveFrom(Optional<T>&& oth) {
    _data = oth._data;
    oth._data = nullptr;
}
template <class T>
void Optional<T>::free() {
    delete _data;
}

template <class T>
Optional<T>::Optional(const Optional<T>& oth) {
    copyFrom(oth);
}
template <class T>
Optional<T>::Optional(Optional<T>&& oth) {
    moveFrom(std::move(oth));
}
template <class T>
Optional<T>& Optional<T>::operator=(const Optional<T>& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }
    return *this;
}
template <class T>
Optional<T>& Optional<T>::operator=(Optional<T>&& oth) {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }
    return *this;    
}
template <class T>
Optional<T>::~Optional() {
    free();
}

template <class T>
const T& Optional<T>::operator*() const {
    return *_data;
}
template <class T>
T& Optional<T>::operator*() {
    return *_data;
}

template <class T>
const T& Optional<T>::operator->() const {
    return *_data;
}
template <class T>
T& Optional<T>::operator->() {
    return *_data;
}

template <class T>
void Optional<T>::reset() {
    free();
}

template <class T>
bool Optional<T>::has_value() const {
    return _data != nullptr;
}