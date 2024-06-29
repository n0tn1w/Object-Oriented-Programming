#include "PF.h"

template <class T>
class PFByCriteria : public PF{

public:

    PFByCriteria(const T&);
    PFByCriteria(T&&);

    PF* clone() const override;

    // Only operator() so function pointer can be given to it
    Pair<int, bool> operator()(int) const override; 
    
private:
    T _data;
};

template <class T>
PFByCriteria<T>::PFByCriteria(const T& data) : _data(data) { }

template <class T>
PFByCriteria<T>::PFByCriteria(T&& data) : _data(std::move(data)) { }

template <class T>
Pair<int, bool> PFByCriteria<T>::operator()(int val) const {
    return _data(val);
}

template<class T>
PF* PFByCriteria<T>::clone() const {
    return new (std::nothrow) PFByCriteria<T>(*this);
}