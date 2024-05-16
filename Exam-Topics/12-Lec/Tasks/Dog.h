#pragma once

#include <iostream>
using std::cout;
using std::endl;

#include "Animal.h"

class Dog : public Animal {

public: 
    void roar() const override;

    AnimalType getAnimalType() const override;

    Animal* clone() const override;
};