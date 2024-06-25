#include "Rectangle.h"

Rectangle::Rectangle(int x0, int y0, int x3, int y3) : Shape(4) {
    setPoint({x0, y0}, 0);
    setPoint({x3, y0}, 1);
    setPoint({x3, y3}, 2);
    setPoint({x0, y3}, 3);
}

double Rectangle::getArea() const {
    int a = Point::Distance(getPoint(0), getPoint(1));
    int b = Point::Distance(getPoint(0), getPoint(3));

    return a * b;
};

double Rectangle::getParam() const {
    int a = Point::Distance(getPoint(0), getPoint(1));
    int b = Point::Distance(getPoint(0), getPoint(3));

    return 2 * (a + b);
}

bool Rectangle::isPointInside(const Point& p) const {
    return getPoint(0).x <= p.x <= getPoint(2).x
            && getPoint(0).y <= p.y <= getPoint(2).y;
};