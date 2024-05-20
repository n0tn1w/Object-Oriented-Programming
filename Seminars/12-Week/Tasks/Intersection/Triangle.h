#pragma once
#include "Shape.h"
#include <iostream>
using std::cout;
using std::endl;

class Triangle : public Shape {
public:
    void intersectWith(Shape*) override;
    void intersectWithTriangle(Shape*) override;
    void intersectWithRectangle(Shape*) override;
    void intersectWithCircle(Shape*) override;
};