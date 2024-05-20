#include "Triangle.h"

void Triangle::intersectWith(Shape* sh) {
    sh->intersectWithTriangle(this);
}

void Triangle::intersectWithTriangle(Shape* sh) {
    cout << "T : T" << endl;
}

void Triangle::intersectWithRectangle(Shape* sh) {
    cout << "T : R" << endl;
}

void Triangle::intersectWithCircle(Shape* sh) {
    cout << "T : C" << endl;
}