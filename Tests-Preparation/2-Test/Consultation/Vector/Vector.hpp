#define TT template <class T, class F>
#define V Vector<T, F>

#include <utility>
#include <stdexcept>
#include <stddef.h>

TT
class Vector {

public:
    Vector();

    Vector(const Vector<T,F>&);
    Vector(Vector<T,F>&&) noexcept;
    Vector<T,F>& operator=(const Vector<T,F>&);
    Vector<T,F>& operator=(Vector<T,F>&&) noexcept;
    ~Vector();

    void add(const T&);
    void add(T&&);

    void add(const char*);

    bool isEmpty() const;

    const T& operator[](size_t) const;
    T& operator[](size_t);

    size_t getSize() const;

private:
    void add(T*);
    //void add(const T*);

    void copyFrom(const Vector<T,F>&);
    void moveFrom(Vector<T,F>&&);
    void resize();
    void free();

    T** _data = nullptr;
    size_t _size = 0, _capacity = 0;
};

TT
V::Vector() {
    _size = 0;
    _capacity = 8;
    _data =  new T*[_capacity];
}
TT
V::Vector(const Vector<T,F>& oth) {
    copyFrom(oth);
}
TT
V::Vector(Vector<T,F>&& oth) noexcept {
    moveFrom(std::move(oth));
}
TT
Vector<T,F>& V::operator=(const Vector<T,F>& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }
    return *this;
}
TT
Vector<T,F>& V::operator=(Vector<T,F>&& oth) noexcept {
     if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }   
    return *this;
}
TT
V::~Vector() {
    free();
}

TT
void V::copyFrom(const Vector<T,F>& oth) {
    _size = oth._size;
    _capacity = oth._capacity;
    _data = new T*[_capacity];

    for(size_t i = 0; i < _size; i++) {
        _data[i] = oth._data[i]->clone();
    }
}

TT
void V::moveFrom(Vector<T, F>&& oth) {
    _size = oth._size;
    _capacity = oth._capacity;
    _data = oth._data;

    oth._data = nullptr;
    oth._capacity = oth._size = 0;
}

TT
void V::resize() {
    _capacity *= 2;
    T** newData = new T*[_capacity];
    for(size_t i = 0; i < _size; i++) {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}

TT
void V::free() {
    for(size_t i = 0; i < _size; i++)
        delete _data[i];
    delete[] _data;
}

TT
const T& V::operator[](size_t index) const {
    return _data[index];
}

TT
T& V::operator[](size_t index) {
    return _data[index];
}

TT
bool V::isEmpty() const {
    return _size == 0;
}

TT
void V::add(const T& elt) {
    if(elt == nullptr)
        throw std::runtime_error("Nullptr elt!");
    
    if(_size == _capacity)
        resize();

    _data[_size++] = elt;
}

TT
void V::add(T&& elt) {

    if(!_data[_size]) {
        *_data[_size] = std::move(elt);
    } else {
        _data[_size] = new T(std::move(elt));
    }
    
    _size++;
} 

TT
void V::add(const char* str) {
    T* obj = F::create(str);
    if(obj) {
        add(obj);
    }
}

TT
void V::add(T* elt) {
    if(_size == _capacity)
        resize();

    _data[_size++] = elt;
}

TT
size_t V::getSize() const {
    return _size;
}

