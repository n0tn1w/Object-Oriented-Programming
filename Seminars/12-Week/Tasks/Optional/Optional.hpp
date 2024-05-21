template <class T>
class Optional {

public:

    Optional() = default;
    Optional(const T&);
    Optional(T&&);

    const T& operator*() const;
    T& operator*();

    operator bool() const ;

    void reset();

private:

    void copyForm(const Optional<T>&);
    T* data = nullptr;
};

template <class T>
void Optional<T>::copyForm(const Optional<T>& oth) {
    if(*oth) {
        data = new T(*oth);
    } else {
        data = nullptr;
    }
}

template <class T>
const T& Optional<T>::operator*() const {
    return *data;
}
template <class T>
T& Optional<T>::operator*() {
    return *data;
}

template <class T>
Optional<T>::operator bool() const {
    return data != nullptr;
}

template <class T>
void Optional<T>::reset() {
    delete data;
    data = nullptr;
}

template <class T>
Optional<T>::Optional(const T& oth) {
    data = new T(oth);
}

template <class T>
Optional<T>::Optional(T&& oth) {
    data = new T(std::move(oth));
}
