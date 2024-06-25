#include "Farm.h"

Farm::Farm() {
    _size = 0;
    _capacity = 4;
    _data = new Animal*[_capacity];
}

Farm::Farm(const Farm& oth) {
    copyFrom(oth);
}

Farm& Farm::operator=(const Farm& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }

    return *this;
}

Farm::~Farm() {
    free();
}

Farm::Farm(Farm&& oth) {
    moveFrom(std::move(oth));
}

Farm& Farm::operator=(Farm&& oth) {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }

    return *this;
}

void Farm::free() {
    for(size_t i = 0; i < _size; i++) {
        delete _data[i];
    }
    delete[] _data;
    _size = 0;
    _capacity = 0;
}

void Farm::copyFrom(const Farm& oth) {
    _size = oth._size;
    _capacity = oth._capacity;

    _data = new Animal*[_capacity];
    
    for(size_t i = 0; i < _size; i++) {
        _data[i] = oth._data[i]->clone();
    }
}

void Farm::moveFrom(Farm&& oth) {
    _size = oth._size;
    _capacity = oth._capacity;
    _data = oth._data;

    oth._data = nullptr;
    oth._size = 0;
    oth._capacity = 0;
}

void Farm::roadAll() const {
    for(size_t i = 0; i < _size; i++) {
        _data[i]->roar();
    }
}

void Farm::resize() {
    _capacity *= 2;
    Animal** temp = new Animal*[_capacity];

    for(size_t i = 0; i < _size; i++) {
        temp[i] = _data[i];
    }

    delete[] _data;
    _data = temp;
}

void Farm::add(Animal* ani) {
    if(ani == nullptr) 
        throw;

    if(_size + 1 > _capacity)
        resize();
    
    _data[_size++] = ani;
}

void Farm::remove(size_t index) {
    if(index < 0 || _size >= index)
        throw;
    
    _data[index] = _data[_size];
    _size--;
}

AnimalType Farm::getTypeByIndex(size_t index) const {
    if(index < 0 || _size >= index)
        throw;
    
    return _data[index]->getAnimalType();
}