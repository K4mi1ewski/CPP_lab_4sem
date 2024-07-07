#include "diamond.h"

double  Diamond::area() const
{
    return (d1*d2)/2.0;
}

double Diamond::diagonal1() const
{
    return d1;
}

double Diamond::diagonal2()const
{
    return d2;
}

bool Diamond::isIn(int x, int y) const
{
    double dist1 = abs(x-center.x());
    dist1 = dist1/(d1/2.0);
    double dist2 = abs(y-center.y());
    dist2 = dist2/(d2/2.0);

    return dist1+dist2<=1.0;
}