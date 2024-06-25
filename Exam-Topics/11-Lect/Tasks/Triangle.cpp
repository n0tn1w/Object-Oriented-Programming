#include "Triangle.h"

Triangle::Triangle(int x0, int y0, int x1, int y1, int x2, int y2) : Shape(3) {
    setPoint({x0, y0}, 0);
    setPoint({x1, y1}, 1);
    setPoint({x2, y2}, 2);
}

double Triangle::getArea() const {
    int a = Point::Distance(getPoint(0), getPoint(1));
    int b = Point::Distance(getPoint(1), getPoint(2));
    int c = Point::Distance(getPoint(2), getPoint(0));

    double halfP = (a + b + c) / 2.0;

    return sqrt(halfP * (halfP - a) * (halfP - b) * (halfP - c));
}

double Triangle::getParam() const {
    int a = Point::Distance(getPoint(0), getPoint(1));
    int b = Point::Distance(getPoint(1), getPoint(2));
    int c = Point::Distance(getPoint(2), getPoint(0));

    return a + b + c;
}

bool Triangle::isPointInside(const Point& p) const {
    Triangle t1(getPoint(0).x, getPoint(0).y, getPoint(1).x, getPoint(1).y, p.x, p.y);
	Triangle t2(getPoint(2).x, getPoint(2).y, getPoint(1).x, getPoint(1).y, p.x, p.y);
	Triangle t3(getPoint(2).x, getPoint(2).y, getPoint(0).x, getPoint(0).y, p.x, p.y);

    //return t1.getArea() + t2.getArea() + t3.getArea() == getArea();
    return abs((t1.getArea() + t2.getArea() + t3.getArea())- getArea()) <= std::numeric_limits<double>::epsilon();
}