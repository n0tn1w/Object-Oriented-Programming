#include "NVector.h"

NVector::NVector() {
    _data = nullptr;
    _size = 0;
}

NVector::NVector(const int* data, size_t size) {
    _size = size;
    _data = new int[size];
    for(size_t i = 0; i < size; i++) {
        _data[i] = data[i];
    }
}

void NVector::copyFrom(const NVector& oth) {
    _size = oth._size;
    _data = new int[oth._size];
    for(size_t i = 0; i < oth._size; i++) {
        _data[i] = oth._data[i];
    }
}

NVector::NVector(const NVector& oth) {
    copyFrom(oth);
}

void NVector::free() {
    delete[] _data;
    _data = nullptr;
    _size = 0;
}

NVector& NVector::operator=(const NVector& oth) {

    if(this != &oth) {
        free();
        copyFrom(oth);
    }

    return *this;
}

NVector::~NVector() {
    free();
}

const int* NVector::getData() const {
    return _data;
}

size_t NVector::getSize() const {
    return _size;
}

void NVector::setData(const int* data, size_t size) {

    free();

    if(data == nullptr) {
        return;
    }

    _data = new int[size];
    for(size_t i = 0; i < size; i++) {
        _data[i] = data[i];
    }
}

int& NVector::operator[](size_t index) {
    if(index >= _size) {
        throw "Index out of bound!";
    }
    
    return _data[index];
}
int NVector::operator[](size_t index) const {
        if(index >= _size) {
        throw "Index out of bound!";
    }
    
    return _data[index];
}


// This could be done as a friend function and not use .getSize() but _size
bool operator==(const NVector& l1, const NVector& l2) {
    size_t len = l1.getSize();
    if(len != l2.getSize()) {
        return false;
    }

    for(size_t i = 0; i < len; i++) {
        if(l1[i] != l2[i]) {
            return false;
        }
    }

    return true;
}

// I dont know why i have left1 and left2 but whatever
bool operator!=(const NVector& l1, const NVector& l2) {
    return !(l1 == l2);
}

void NVector::pushBack(int el) {
    _size++;
    int* newData = new int[_size];

    for(size_t i = 0; i < _size - 1; i++) {
        newData[i] = _data[i];
    }
    newData[_size - 1] = el;
    delete[] _data;

    _data = newData;
}

std::ostream& operator<<(std::ostream& os, const NVector& oth) {
    os << "[";
    for(size_t i = 0; i < oth._size; i++) {
        if(i != 0) {
            os << ", ";
        }
        os << oth[i];
    }
    return os << "]";
}

std::istream& operator>>(std::istream& is, NVector& oth) {
    is >> oth._size;
    oth._data = new int[oth._size];
    for(size_t i = 0;  i < oth._size; i++) {
        is >> oth[i];
    }
    return is;
}
NVector& NVector::operator+=(const NVector& oth) {
    if(_size != oth._size) {
        throw "Index out of range! Vecotrs size doesnt match";
    }

    for(size_t i = 0; i < _size; i++) {
        _data[i] += oth[i];
    }

    return *this;
}


NVector operator+(const NVector& l1, const NVector& l2) {
    NVector temp(l1);
    temp += l2;
    return temp;
}

NVector& NVector::operator-=(const NVector& oth) {
    if(_size != oth._size) {
        throw "Index out of range! Vecotrs size doesnt match";
    }

    for(size_t i = 0; i < _size; i++) {
        _data[i] -= oth[i];
    }
    return *this;

}


NVector operator-(const NVector& l1, const NVector& l2) {
    NVector temp(l1);
    temp -= l2;
    return temp;
}

NVector operator*(const NVector& vect, int scalar) {
    NVector newVector(vect);

    size_t len = vect.getSize();
    for(size_t i = 0; i < len; i++) {
        newVector[i] *= scalar;
    }

    return newVector;
}


namespace Helper {
    constexpr double marginOfError = 0.000001;

    bool compareDoubles(double l1, double l2) {
        return (l1 - l2 < 0.000001);
    }
};

bool operator||(const NVector& l1, const NVector& l2) {
    size_t len = l1.getSize();
    if(len != l2.getSize()) {
        return false;
    }

    if (len == 0) {
        return true;
    }
    
    double mod =  double(l1[0]) / l2[0];

    for(size_t i = 1; i < len; i++) {
        double checkMod = double(l1[0]) / l2[0];
        if(!Helper::compareDoubles(mod, checkMod)) {
            return false;
        }
    }

    return true;
}

size_t operator%(const NVector& l1, const NVector& l2) {
    
    size_t len = l1.getSize();
    if(len != l2.getSize()) {
        return false;
    }

    size_t res = 0;
    for(size_t i = 0; i < len; i++) {
        res += (l1[i] * l2[i]);
    }

    return res;
}

bool operator|=(const NVector& l1, const NVector& l2) {
    return l1 % l2 == 0;
}  
