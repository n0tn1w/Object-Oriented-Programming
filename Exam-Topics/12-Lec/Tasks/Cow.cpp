#include "Cow.h"

void Cow::roar() const {
    cout << "muu muu" << endl;
}

AnimalType Cow::getAnimalType() const {
    return AnimalType::Cow;
}

Animal* Cow::clone() const {
    return new (std::nothrow) Cow(*this);
}