/**
 Ciąg dalszy zadania: dodajemy klasę Triangle, która należy do grupy figur podstawowych (BasicShape)opisaną przez trzy punkty
 Dodajemy jeszcze klasę ShapeComposite stanowiącą kompozycję kształtów na zasadzie sumy, iloczynu albo różnicy dwóch figur, zawierająca wskaźniki shared_ptr<Shape> oraz klasę enum z wartościami {INTERSECTION, SUM, DIFFERENCE}.
 Wskazówka:
 Aby sprawdzić, czy punkt należy do trójkąta, należy pamiętać, ze punkt ten dzieli trójkąt na trzy różne trójkąty, ktorych suma jest równa polu trójkąta.
 Proszę skorzystać z wzoru na pole trójkąta: 
 Wzór na pole trójkąta ABC o wierzchołkach A = (xa, ya), B = (xb, yb), C = (xc, yc):
 P = 0.5 * |(xb − xa)(yc − ya) − (yb − ya)(xc − xa)|
 albo inaczej P = 0.5 * |xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb)|
**/

#include <iostream>
#include <memory>
#include <cmath>
#include "shapes.h"
#include "stage.h"
#include "circle.h"
#include "rectangle.h"
#include "diamond.h"
#include "triangle.h"
#include "shapeComposite.h"

#ifndef M_PI
    constexpr double M_PI = 3.1415926;
#endif

using std::cout;
using std::endl;

/// @brief funkcja wykorzystywana do rysowania
void printShape(const Shape* shape, size_t width, size_t heigh)
{
        const Stage stage(width, heigh);
        stage.drawShape(shape, std::cout); ///definiujemy obszar i figurę do narysowania
}

int main()
{
    cout << "=== RYSUJEMY PROSTOKAT ===" << endl;
    int xFrom = 0, yFrom = 0, xTo = 6, yTo = 4;
    const Point from(0,0), to(4,3);
    const Rectangle rectangle(from.x(), from.y(), xTo, yTo);
    const Rectangle rectangle2(from, to);
    cout << "Area = " << rectangle2. area() << std::endl;
    cout << "Diagonal 1 = Diagonal 2 = " << rectangle2.diagonal1() << std::endl;
    printShape(&rectangle2, 4, 3);
   
    cout << "=== RYSUJEMY KOLO ===" << endl;
    const Point center(xFrom +(xTo-xFrom)/2, yTo);
    auto radius = (xTo - xFrom)/2;
    const Circle circle(center.x(), center.y(), radius);
    cout << "Area = " << circle. area() << std::endl;
    printShape(&circle, xTo, yTo + radius);

    cout << "=== RYSUJEMY ROMB  ===" << endl;
    const Diamond diamond(Point(2,3), 4, 6); //(x,y), d1, d2
    cout << "Area = " << diamond. area() << std::endl;
    cout << "Diagonal 1 = " << diamond.diagonal1() << std::endl;
       cout << "Diagonal 2 = " << diamond.diagonal2() << std::endl;
    printShape(&diamond, 8, 6);
    // Diamond diamond2(3, 3, 5, 5); //x, y, d1, d2
    // cout << "Area = " << diamond2. area() << std::endl;
    // printShape(&diamond2, 5, 5);

    cout << "=== RYSUJEMY TROJKAT ===" << endl;
    const Triangle triangle(Point(0,0), Point(6,0), Point(3,3));
    cout << "Area = " << triangle. area() << std::endl;
    printShape(&triangle, 8, 3);
    Triangle rightTriangle(Point(0,0), Point(5,0), Point(0,5));
    cout << "Area = " << rightTriangle.area() << std::endl;
    printShape(&rightTriangle, 5, 5);

    /// zabawa z klasą ShapeComposite powstałej jako suma, różnica albo iloczyn figur
    cout << "=== RYSUJEMY PROSTOKAT + KOLO ===" << endl;
    std::shared_ptr<Rectangle> prectangle = std::make_shared<Rectangle>(rectangle);
    std::shared_ptr<const Shape> composite1(new ShapeComposite(prectangle, std::make_shared<const Circle>(circle), ShapeOperation::SUM));
    printShape(composite1.get(), xTo, yTo+radius);
    cout << "=== RYSUJEMY PROSTOKAT * ROMB ===" << endl;
    std::shared_ptr<Shape> composite2(new ShapeComposite(prectangle, std::make_shared<Diamond>(diamond), ShapeOperation::INTERSECTION));
    printShape(composite2.get(), xTo, yTo+radius-2);
    cout << "=== RYSUJEMY PROSTOKAT - TROJKAT ===" << endl;
    ShapeComposite composite3(ShapeComposite(prectangle, std::make_shared<Triangle>(triangle), ShapeOperation::DIFFERENCE));
    printShape(&composite3, xTo, yTo+radius-3);

    cout << "=== SPRAWDZAMY DZIEDZICZENIE ===" << endl;
    unsigned numObj = 6;
	  const Shape *list[]{prectangle.get(), new Circle(center, 3), &diamond,&triangle, composite1.get(), &composite3};
	  for (unsigned i = 0; i < numObj; ++i){
		  std::cout << "*** Obiekt " << i+1 << " ***\n";
      // printShape(list[i], xTo, yTo+radius); //można go wydrukować
    /// tylko dla figur podstawowych możemy obliczyć pole ze wzoru
      const BasicShape* closed = dynamic_cast<const BasicShape*>(list[i]);
		  if (closed) std::cout << "Area = " << closed->area() << std::endl;
    /// tylko Rectangle i Diamond ma przekątne, które możemy obliczyć
		  const HasDiagonal* diag = dynamic_cast<const HasDiagonal*>(list[i]);
  		if(diag) {
        std::cout << "Diagonal 1 = " << diag->diagonal1() << std::endl;
        std::cout << "Diagonal 2 = " << diag->diagonal2() << std::endl;
	    }
    }

   /// na koniec trochę zabawy, ta część sama powinna się już narysować
    cout << "=== I NA KONIEC DLA WYTRWALYCH DOMEK ===" << endl;
    std::shared_ptr<Shape> home(new Rectangle(0, 0, 20, 10));
    // std::shared_ptr<Shape> roof(new Circle(10, 11, 10));
    std::shared_ptr<Shape> roof(new Triangle(Point(0,11), Point(20,11), Point(10,22)));
    std::shared_ptr<Shape> homeWithRoof(new ShapeComposite(home, roof, ShapeOperation::SUM));
    std::shared_ptr<Shape> door(new Rectangle(3, 1, 9, 11));
    std::shared_ptr<Shape> homeWithDoor(new ShapeComposite(homeWithRoof, door, ShapeOperation::DIFFERENCE));
    std::shared_ptr<Shape> window(new Rectangle(13, 7, 17, 11));
    std::shared_ptr<Shape> homeWithDoorAndWindow(new ShapeComposite(homeWithDoor, window, ShapeOperation::DIFFERENCE));
    printShape(homeWithDoorAndWindow.get(), 20, 20);

}

/* wynik
=== RYSUJEMY PROSTOKAT ===
Area = 12
Diagonal 1 = Diagonal 2 = 5
3:      * * * * * 
2:      * * * * * 
1:      * * * * * 
0:      * * * * * 
=== RYSUJEMY KOLO ===
Area = 28.2743
7:            *       
6:        * * * * *   
5:        * * * * *   
4:      * * * * * * *
3:        * * * * *
2:        * * * * *
1:            *
0:
=== RYSUJEMY ROMB  ===
Area = 24
Diagonal 1 = 4
Diagonal 2 = 6
6:          *
5:          *
4:        * * *
3:      * * * * *
2:        * * *
1:          *
0:          *
=== RYSUJEMY TROJKAT ===
Area = 9
3:            *
2:          * * *
1:        * * * * *
0:      * * * * * * *
Area = 12.5
5:      *
4:      * *
3:      * * *
2:      * * * *
1:      * * * * *
0:      * * * * * *
=== RYSUJEMY PROSTOKAT + KOLO ===
7:            *
6:        * * * * *
5:        * * * * *
4:      * * * * * * *
3:      * * * * * * *
2:      * * * * * * *
1:      * * * * * * *
0:      * * * * * * *
=== RYSUJEMY PROSTOKAT * ROMB ===
5:
4:        * * *
3:      * * * * *
2:        * * *
1:          *
0:          *
=== RYSUJEMY PROSTOKAT - TROJKAT ===
4:      * * * * * * *
3:      * * *   * * *
2:      * *       * *
1:      *           *
0:
=== SPRAWDZAMY DZIEDZICZENIE ===
*** Obiekt 1 ***
Area = 24
Diagonal 1 = 7.2111
Diagonal 2 = 7.2111
*** Obiekt 2 ***
Area = 28.2743
*** Obiekt 3 ***
Area = 24
Diagonal 1 = 4
Diagonal 2 = 6
*** Obiekt 4 ***
Area = 9
*** Obiekt 5 ***
*** Obiekt 6 ***
=== I NA KONIEC DLA WYTRWALYCH DOMEK ===
20:                       * * *
19:                     * * * * *
18:                   * * * * * * *
17:                 * * * * * * * * *
16:               * * * * * * * * * * *
15:             * * * * * * * * * * * * *
14:           * * * * * * * * * * * * * * *
13:         * * * * * * * * * * * * * * * * *
12:       * * * * * * * * * * * * * * * * * * *
11:     * * *               * * *           * * *
10:     * * *               * * *           * * *
9:      * * *               * * *           * * *
8:      * * *               * * *           * * *
7:      * * *               * * *           * * *
6:      * * *               * * * * * * * * * * *
5:      * * *               * * * * * * * * * * *
4:      * * *               * * * * * * * * * * *
3:      * * *               * * * * * * * * * * *
2:      * * *               * * * * * * * * * * *
1:      * * *               * * * * * * * * * * *
0:      * * * * * * * * * * * * * * * * * * * * *
*/
