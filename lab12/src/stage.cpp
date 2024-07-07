#include "stage.h"

void Stage::drawShape(const Shape* shape, ostream& os) const{
    for (int i = h; i>=0;i--)
    {
        os << i  << ":"<< "\t" ;
        for(int j = 0;j<=w;j++)
        {
            if (shape->isIn(j,i))
                os << "* ";
            else
                os << "  ";
        }
        os << endl;
    }
}