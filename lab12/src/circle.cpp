#include "circle.h"
#ifndef M_PI
    constexpr double M_PI = 3.1415926;
#endif
double Circle::area() const
{
    return radius*radius* M_PI;
}

bool Circle::isIn(int x, int y) const
{
    int x_distance = cntr.x()-x;
    int y_distance = cntr.y()-y;
    
    double distance = pow(x_distance,2) + pow(y_distance,2);
    distance = sqrt(distance);
    return (distance <= static_cast<double>(radius)); 
}

