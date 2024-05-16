#include "Dog.h"

void Dog::roar() const {
    cout << "bao bao" << endl;
}

AnimalType Dog::getAnimalType() const {
    return AnimalType::Dog;
}

Animal* Dog::clone() const {
    return new (std::nothrow) Dog(*this);
}
