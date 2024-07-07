#pragma once
#include "shapes.h"
#include <memory>
enum class ShapeOperation {SUM, INTERSECTION, DIFFERENCE};

class ShapeComposite: public Shape
{
    public:
    ShapeComposite(std::shared_ptr<const Shape> ptr1, std::shared_ptr<const Shape> ptr2, ShapeOperation operation): p1(ptr1), p2(ptr2), operation_(operation) {}
    bool isIn(int x, int y) const override;
    private:

    std::shared_ptr<const Shape> p1;
    std::shared_ptr<const Shape> p2;
    ShapeOperation operation_;
};
