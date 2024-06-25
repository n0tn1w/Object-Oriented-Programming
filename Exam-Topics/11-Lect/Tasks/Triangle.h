#pragma once
#include "Shape.h"
#include <limits>

class Triangle : public Shape {

public:

    Triangle(int, int, int, int, int, int);

    double getArea() const override;
    double getParam() const override;
    bool isPointInside(const Point&) const override;

};