#include "Circle.h"

void Circle::intersectWith(Shape* sh) {
    sh->intersectWithCircle(this);
}

void Circle::intersectWithTriangle(Shape* sh) {
    cout << "C : T" << endl;
}

void Circle::intersectWithRectangle(Shape* sh) {
    cout << "C : R" << endl;
}

void Circle::intersectWithCircle(Shape* sh) {
    cout << "C : C" << endl;
}