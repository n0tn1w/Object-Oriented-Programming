#include <iostream>
using namespace std;
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"


int main() {
    Shape* s1 = new Rectangle();
    Shape* s2 = new Circle();
    Shape* s3 = new Triangle();

    s2->intersectWith(s1);
    s1->intersectWith(s3);
    s3->intersectWith(s3);
}