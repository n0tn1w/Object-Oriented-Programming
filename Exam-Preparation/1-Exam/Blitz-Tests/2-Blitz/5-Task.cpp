// 5. Посочете грешките в кода:

#include <iostream>
class Point {
    int x;
    int y;

public:
    Point() = default;
    
    Point(int x, int y) {
        x = x;
        y = y;
    }
};
int main()
{
    Point p1;
}

// No default contructor wont compile