#include "Cat.h"

void Cat::roar() const {
    cout << "meow meow" << endl;
}

AnimalType Cat::getAnimalType() const {
    return AnimalType::Cat;
}

Animal* Cat::clone() const {
    return new (std::nothrow) Cat(*this);
}

