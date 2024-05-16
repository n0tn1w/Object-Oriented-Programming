#pragma once
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Cow.h"
#include "Animal.h"

class Factory {
public:
    static Animal* createAnimal(AnimalType);
};