#include "Shape.h"

Shape::Shape(unsigned count) {
    _pointsCount = count;
    _points = new Point[_pointsCount];
}

Shape::Shape(const Shape& oth) {
    copyFrom(oth);
}

Shape& Shape::operator=(const Shape& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }

    return *this;
}

Shape::~Shape() {
    free();
}

Shape::Shape(Shape&& oth) {
    moveFrom(std::move(oth));
}

Shape& Shape::operator=(Shape&& oth) {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }

    return *this;
}

void Shape::copyFrom(const Shape& oth) {
    _pointsCount = oth._pointsCount;
    _points = new Point[_pointsCount];

    for(unsigned i = 0; i < _pointsCount; i++) {
        _points = new Point(oth._points[i]);
    }
}

void Shape::moveFrom(Shape&& oth) {
    _pointsCount = oth._pointsCount;
    _points = oth._points;

    oth._pointsCount = 0;
    oth._points = nullptr;
}

void Shape::free() {
    delete[] _points;
    _pointsCount = 0;
}

void Shape::setPoint(const Point& point, unsigned index) {
    if(index >= _pointsCount) {
        throw std::logic_error("");
    }
    _points[index] = point;
}

Point Shape::getPoint(unsigned index) const {
    return _points[index];
}
