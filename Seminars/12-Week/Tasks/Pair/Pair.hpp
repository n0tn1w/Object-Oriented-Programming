#include <exception>

template< class T, class V>
class  Pair
{
public:
    Pair(const T&, const V&);
    Pair(T&&, V&&);

    const T& getFirst() const;
    const V& getSecond() const;

    void setFirst(const T&);
    void setFirst(T&&);

    void setSecond(const V&);
    void setSecond(V&&);

private:
    T f;
    V s;
};

template <class T, class V>
Pair<T,V>::Pair(const T& f, const V& s) : f(f), s(s) {}

template <class T, class V>
Pair<T,V>::Pair(T&& f, V&& s) : f(std::move(f)), s(std::move(s)) {}

template <class T, class V>
const T& Pair<T,V>::getFirst() const {
    return f;
}

template <class T, class V>
const V& Pair<T,V>::getSecond() const {
    return s;
}

template <class T, class V>
void Pair<T,V>::setFirst(const T& fn) {
    if(!fn)
        throw std:: logic_error("Element is nullptr!");
    f = fn;
}

template <class T, class V>
void Pair<T,V>::setFirst(T&& fn) {
    f = std::move(fn);
}

template <class T, class V>
void Pair<T,V>::setSecond(const V& sn) {
    if(!sn)
        throw std:: logic_error("Element is nullptr!");
    f = sn;
}

template <class T, class V>
void Pair<T,V>::setSecond(V&& sn) {
    s = std::move(sn);
}
