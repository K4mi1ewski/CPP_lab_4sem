#include "rectangle.h"



double Rectangle::diagonal1() const 
{
 int x_len = p2.x() - p1.x();
 int y_len = p2.y() - p1.y();
 return hypot(x_len, y_len);
}

double Rectangle::diagonal2() const{
    return diagonal1();
}

double Rectangle::area() const
{
    int x_len = p2.x()-p1.x();
    int y_len = p2.y()-p1.y();
    return x_len*y_len;
}

bool Rectangle::isIn(int x, int y) const
{
    return (min(p1.x(),p2.x()) <= x && max(p1.x(),p2.x())>=x && max(p1.y(),p2.y())>=y && min(p1.y(),p2.y()) <= y);
}