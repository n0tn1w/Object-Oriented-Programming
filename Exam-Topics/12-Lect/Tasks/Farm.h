#include "Cat.h"

class Farm {

public:

    Farm();
    Farm(const Farm&);
    Farm& operator=(const Farm&);
    ~Farm();

    Farm(Farm&&);
    Farm& operator=(Farm&&);

    void roadAll() const;

    void add(Animal*);
    void remove(size_t);

    AnimalType getTypeByIndex(size_t) const;

private:

    void copyFrom(const Farm&);
    void moveFrom(Farm&&);
    void free();

    void resize();

    Animal** _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

};