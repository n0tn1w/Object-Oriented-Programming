#pragma once
#include <utility>
#include <stdexcept>
#include <math.h>

struct Point
{
    int x = 0, y = 0;

    int static Distance(const Point& l, const Point& r) {
        int dx = l.x - r.x;
        int dy = l.y - r.y;
        return sqrt(dx * dx + dy * dy);
    }
};

namespace ShapesConst {
    double static PI = 3.14;
}


class Shape {

public:

    virtual double getParam() const = 0;
    virtual double getArea() const = 0;
    virtual bool isPointInside(const Point&) const = 0;

    virtual ~Shape();

protected:

    Shape() = default;
    Shape(unsigned);
    Shape(const Shape&);
    Shape& operator=(const Shape&);

    Shape(Shape&&);
    Shape& operator=(Shape&&);

    void setPoint(const Point&, unsigned);
    Point getPoint(unsigned) const;

private:

    void copyFrom(const Shape&);
    void moveFrom(Shape&&);
    void free();

    Point* _points = nullptr;
    unsigned _pointsCount = 0;

};