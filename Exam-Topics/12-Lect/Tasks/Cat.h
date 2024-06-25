#pragma once

#include <iostream>
using std::cout;
using std::endl;

#include "Animal.h"

class Cat : public Animal {

public: 
    void roar() const override;

    AnimalType getAnimalType() const;

    Animal* clone() const override;
};