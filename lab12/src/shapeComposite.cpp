#include "shapeComposite.h"


bool ShapeComposite::isIn(int x, int y) const
{
    if (operation_ == ShapeOperation::SUM)
    {
        return (p1->isIn(x,y) || p2->isIn(x,y));
    }
    else if (operation_ == ShapeOperation::INTERSECTION)
    {
        return (p1->isIn(x,y) && (p2->isIn(x,y)));
    }
    else if (operation_ == ShapeOperation::DIFFERENCE)
    {
        return (p1->isIn(x,y) && !(p2->isIn(x,y)));
    }
    return false;
}