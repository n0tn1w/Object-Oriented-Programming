#include <utility>
#include <exception>

template <typename T, typename D>
class Pair {

public:

    Pair() = default;

    Pair(const T&, const D&);
    Pair(const T&, D&&);
    Pair(T&&, const D&);
    Pair(T&&, D&&);

    const T& first() const;
    T& first();
    const D& second() const;
    D& second();

    void setFirst(const T&);
    void setSecond(const D&);

    void setFirst(T&&);
    void setSecond(D&&);

private:

    T _f;
    D _s;

};

template <typename T, typename D>
Pair<T,D>::Pair(const T& f, const D& s) : _f(f), _s(s) {}

template <typename T, typename D>
Pair<T,D>::Pair(const T& f, D&& s)  : _f(f), _s(std::move(s)) {}

template <typename T, typename D>
Pair<T,D>::Pair(T&& f, const D& s) : _f(std::move(f)), _s(s) {}

template <typename T, typename D>
Pair<T,D>::Pair(T&& f, D&& s) : _f(std::move(f)), _s(std::move(s)) {}

template <typename T, typename D>
const T& Pair<T,D>::first() const {
    return _f;
}

template <typename T, typename D>
T& Pair<T,D>::first() {
    return _f;
}

template <typename T, typename D>
const D& Pair<T,D>::second() const {
    return _s;
}

template <typename T, typename D>
D& Pair<T,D>::second() {
    return _s;
}

template <typename T, typename D>
void Pair<T,D>::setFirst(const T& f) {
    _f = f;
}

template <typename T, typename D>
void Pair<T,D>::setSecond(const D& s) {
    _s = s;
}

template <typename T, typename D>
void Pair<T,D>::setFirst(T&& f) {
    _f = std::move(f);
}

template <typename T, typename D>
void Pair<T,D>::setSecond(D&& s) {
    _s = std::move(s);
}
