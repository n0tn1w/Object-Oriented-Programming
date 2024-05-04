#pragma once
#include "Shape.h"

class Rectangle : public Shape {

public:

    Rectangle(int, int, int, int);

    double getArea() const override;
    double getParam() const override;
    bool isPointInside(const Point&) const override;

};