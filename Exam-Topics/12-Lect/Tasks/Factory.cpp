#include "Factory.h"

Animal* Factory::createAnimal(AnimalType aT) {
    if(aT == AnimalType::Cat) {
        return new Cat();
    } else if (aT == AnimalType::Dog) {
        return new Dog();
    } else if (aT == AnimalType::Cow) {
        return new Cow();
    } else {
        return nullptr;
    }
}