#define TT template <class T>
#define O Optional<T>

TT
class Optional {

public:

    Optional() = default;
    // Optional(const O&);
    // Optional(O&&);
    // O& operator=(const O&);
    // O& operator=(O&&);
    // ~Optional();

    Optional(const T*);
    Optional(T*&&);

    void set_value(const T*);
    void set_value(T*&&);


    T* getData();
    const T& getValue() const;
    T& getValue();
    bool has_value() const;
    void reset();

private:
    // void free();
    // void copyFrom(const O&);
    // void moveFrom(O&&);

    T* _data = nullptr;
};

TT
bool O::has_value() const {
    return _data != nullptr;
}

TT
void O::reset() {
    delete _data;
    _data = nullptr;
}

TT
void O::set_value(const T* el) {
    delete _data;
    _data = el;
}

TT
void O::set_value(T*&& elt) {
    delete _data;
    _data = std::move(elt);
}

TT
const T& O::getValue() const {
    if(_data == nullptr)
        throw "Nullptr";
    return *_data;
}

TT
T& O::getValue() {
    if(_data == nullptr)
        throw "Nullptr";
    return *_data;
}

TT
T* O::getData() {
    return _data;
}

TT
O::Optional(const T* elt) {
    set_value(_data);
}
TT
O::Optional(T*&& elt) {
    set_value(std::move(_data));
}
