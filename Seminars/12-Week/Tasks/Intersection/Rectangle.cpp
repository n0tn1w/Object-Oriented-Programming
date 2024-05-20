#include "Rectangle.h"

void Rectangle::intersectWith(Shape* sh) {
    sh->intersectWithRectangle(this);
}

void Rectangle::intersectWithTriangle(Shape* sh) {
    cout << "R : T" << endl;
}

void Rectangle::intersectWithRectangle(Shape* sh) {
    cout << "R : R" << endl;
}

void Rectangle::intersectWithCircle(Shape* sh) {
    cout << "R : C" << endl;
}