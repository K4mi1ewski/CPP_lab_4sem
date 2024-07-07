#pragma once
#include "shapes.h"

class Triangle: public BasicShape
{
    public:
    Triangle(const Point& a, const Point& b, const Point& c):A(a),B(b),C(c){}

    double area() const override;
    bool isIn(int x, int y) const override;
    private:
    Point A;
    Point B;
    Point C;
};