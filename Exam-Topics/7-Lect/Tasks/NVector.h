#ifndef N_VECTOR
#define N_VECTOR

#include <stddef.h>
#include <fstream>

class NVector {

    int* _data;
    size_t _size;

public:

    NVector();
    NVector(const int*, size_t);
    NVector(const NVector&);
    NVector& operator=(const NVector&);
    ~NVector();

    const int* getData() const;
    size_t getSize() const;
    void setData(const int*, size_t);

    void pushBack(int); // have this so that i can add element easier

    int& operator[](size_t);
    int operator[](size_t) const;

    NVector& operator+=(const NVector&);
    NVector& operator-=(const NVector&);


    friend std::ostream& operator<<(std::ostream&, const NVector&);
    friend std::istream& operator>>(std::istream&, NVector&);

private:

    void copyFrom(const NVector&);
    void free();
};

NVector operator+(const NVector&, const NVector&);
NVector operator-(const NVector&, const NVector&);
NVector operator*(const NVector&, int);

// Are parallel
bool operator||(const NVector&, const NVector&);
// Product 
// Abe na bulgarski kato imash 2 vektora i umnojenieto im e u.v = |u||v|.cosY 
// poneje cos90 = 0 trqbva da namerim u.v kato umnojim tochka po tochka
size_t operator%(const NVector&, const NVector&);
bool operator|=(const NVector&, const NVector&);


bool operator==(const NVector&, const NVector&);
bool operator!=(const NVector&, const NVector&);

#endif