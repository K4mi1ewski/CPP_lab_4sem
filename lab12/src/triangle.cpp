#include "triangle.h"

double Triangle::area() const
{
    return 0.5 * abs((B.x()-A.x())*(C.y()-A.y()) - (B.y()-A.y())*(C.x()-A.x()));
}

bool Triangle::isIn(int x, int y) const
{
    Point X (x,y);
    Triangle ABX (A,B,X);
    Triangle BXC(B,X,C);
    Triangle AXC (A,X,C);

    if (area() == ABX.area()+BXC.area()+AXC.area())
        return true;
    else
        return false;
}