#define TT template<class T>
#define PP PolyPtr<T>

TT
class PolyPtr {

public:

    PolyPtr() = default;

    PolyPtr(T*);
    PolyPtr(T*&&);

    PolyPtr(const PolyPtr&);
    PolyPtr(PolyPtr&&);
    PolyPtr<T>& operator=(const PolyPtr&);
    PolyPtr<T>& operator=(PolyPtr&&);
    ~PolyPtr();

private:

    void free();
    void copyFrom(const PolyPtr&);
    void moveFrom(PolyPtr&&);

    T* _data = nullptr;

};

TT
PP::PolyPtr(T* obj) {
    if(obj)
        _data = new T(*obj);
}

TT
PP::PolyPtr(T*&& obj) {
    if(obj)
        _data = std::move(*obj);
}

TT
void PP::free() {
    delete _data;
}

TT
void PP::copyFrom(const PolyPtr& other) {
    _data = other._data->clone();
}

TT
void PP::moveFrom(PolyPtr&& other) {
    _data = other._data;
    other._data = nullptr;
} 


