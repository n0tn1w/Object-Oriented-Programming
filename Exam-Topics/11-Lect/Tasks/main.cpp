#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using std::cout;
using std::endl;

int main() {
    Circle c(0, 0, 3);
    cout << c.getArea() << " " << c.getParam() << " " << c.isPointInside({1, 1}) << endl;

    Rectangle r(0, 0, 3, 3);
    cout << r.getArea() << " " << r.getParam() << " " << r.isPointInside({1, 1}) << endl;

    Triangle t(0, 0, 0, 1, 1, 1);
    cout << t.getArea() << " " << t.getParam() << " " << t.isPointInside({1, 1}) << endl;
}