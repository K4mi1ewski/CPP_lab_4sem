#pragma once
#include "shapes.h"
/**
 * @class Klasa reprezentujaca kolo
*/
class Circle: public BasicShape
{

    public:
    /**
     * @brief Konstruktor trzyargumentowy
     * @param x Wspolrzedna x srodka okregu
     * @param y Wspolrzedna y srodka okregu
     * @param r Dlugosc promienia okregu
    */
    Circle(int x, int y, int r): cntr(x,y),radius(r){}
  
    Circle (const Point& p, int r): cntr(p), radius(r){}

    /**
     * @brief Wirtualna metoda zwracajaca pole okregu
    */
    double area() const override;

    /**
     * @brief Metoda wirtualna sprawdzajaca, czy dany punkt nalezy do srodka okregu
     * @param x Wspolrzedna x punktu do sprawdzenia
     * @param y Wspolrzedna y punktu do sprawdzenia
    */
    bool isIn(int x, int y) const override; 

    private:
    Point cntr; ///<Punkt reprezentujacy srodek okregu
    int radius; ///<Dlugosc promienia okregu
};