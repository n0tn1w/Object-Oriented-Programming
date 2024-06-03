#include "PF.h"

template <class T>
class PFByCriteria : public PF{

public:

    PFByCriteria(const T&);
    PFByCriteria(T&&);

    PF* clone() const override;

protected:

    int evaluate(int) const override;
    bool isDefined(int) const override;
    
private:
    T _data;
};

template <class T>
PFByCriteria<T>::PFByCriteria(const T& data) : _data(data) { }

template <class T>
PFByCriteria<T>::PFByCriteria(T&& data) : _data(std::move(data)) { }

template <class T>
int PFByCriteria<T>::evaluate(int val) const {
    return _data.evaluate(val);
};

template <class T>
bool PFByCriteria<T>::isDefined(int val) const {
    return _data.isDefined(val);
};

template<class T>
PF* PFByCriteria<T>::clone() const {
    return new (std::nothrow) PFByCriteria<T>(*this);
}