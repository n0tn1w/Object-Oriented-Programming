#pragma once

class Shape {

public:

    virtual void intersectWith(Shape*) = 0;
    virtual void intersectWithTriangle(Shape*) = 0;
    virtual void intersectWithRectangle(Shape*) = 0;
    virtual void intersectWithCircle(Shape*) = 0;

    virtual ~Shape() =  default;

};