#pragma once

enum class AnimalType {
    Cat,
    Dog,
    Cow
};

class Animal {

public:


    virtual void roar() const = 0;
    virtual Animal* clone() const = 0;
    virtual ~Animal() = default;

    virtual AnimalType getAnimalType() const = 0;
};