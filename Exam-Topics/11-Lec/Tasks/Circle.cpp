#include "Circle.h"

Circle::Circle(int x, int y, int radius) : Shape(1), _radius(radius) { 
    Shape::setPoint({x, y}, 0);
}

double Circle::getArea() const {
    return ShapesConst::PI * _radius * _radius;
}

double Circle::getParam() const {
    return 2 * ShapesConst::PI * _radius;
}

bool Circle::isPointInside(const Point& p) const {
    return Point::Distance(getPoint(0), p) <=_radius;
}

