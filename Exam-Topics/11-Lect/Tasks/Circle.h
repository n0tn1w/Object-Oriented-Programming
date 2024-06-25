#pragma once
#include "Shape.h"

class Circle : public Shape {

public:

    Circle(int, int, int);

    double getArea() const override;
    double getParam() const override;
    bool isPointInside(const Point&) const override;

private:

    Circle() = default;

    int _radius = 0;

};