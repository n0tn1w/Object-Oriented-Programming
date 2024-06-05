#include "PFContainer.h"

PFContainer::PFContainer(const PFContainer& oth) {
    copyFrom(oth);
}

PFContainer::PFContainer(PFContainer&& oth) noexcept {
    moveFrom(std::move(oth));
}

PFContainer& PFContainer::operator=(const PFContainer& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }

    return *this;
}

PFContainer& PFContainer::operator=(PFContainer&& oth) noexcept {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }

    return *this;
}

PFContainer::~PFContainer() {
    free();
}

void PFContainer::copyFrom(const PFContainer& oth) {
    _data = new PF*[oth._size];
    _size = oth._size;

    for(size_t i = 0; i < oth._size; i++) {
        _data[i] = oth._data[i]->clone();
    }
}

void PFContainer::moveFrom(PFContainer&& oth) {
    _size = oth._size;
    _data = oth._data;

    oth._data = nullptr;
    oth._size = 0;
}

void PFContainer::free() {
    for(size_t i = 0; i < _size; i++) {
        delete _data[i];
    }
    delete[] _data;
}

PFContainer::PFContainer(const PF* const* funcs, size_t size) {
    _data = new PF*[size];
    _size = size;

    for(size_t i = 0; i < size; i++) {
        _data[i] = funcs[i]->clone();
    }
}

PFContainer::PFContainer(PF**&& funcs, size_t size) {
    _data = funcs;
    _size = size;
}

bool PFContainer::isEmpty() const {
    return _size == 0;
}