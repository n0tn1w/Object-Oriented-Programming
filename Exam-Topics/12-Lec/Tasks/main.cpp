#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Cow.h"
#include "Factory.h"
#include "Farm.h"
using std::cout;
using std::endl;

int main() {
    Farm f;
    f.add(Factory::createAnimal(AnimalType::Dog));
    f.add(Factory::createAnimal(AnimalType::Cat));
    f.add(Factory::createAnimal(AnimalType::Cow));
    f.add(Factory::createAnimal(AnimalType::Dog));

    f.roadAll();
}