#pragma once
#include "shapes.h"
/**
 * @class Klasa reprezentujaca romb
*/
class Diamond: public HasDiagonal
{
    public:
    /**
     * @brief Konstruktor trojargumentowy
     * @param p Punkt przeciecia przekatnych w rombie
     * @param e Dlugosc pierwszej przekatnej w rombie (rownoleglej do osi OX)
     * @param f Dlugosc drugiej przekatnej w rombie (rownoleglej do osi OY)
    */
        Diamond (const Point& p, int e, int f): center(p), d1(e), d2(f) {}

        /**
         * @brief Konstuktor czteroargumentowy
         * @param x Wspolrzedna x punktu przeciecia przekatnych
         * @param y Wspolrzedna y punktu przeciecia przekatnych
         * @param e Dlugosc pierwszej przekatnej w rombie (rownoleglej do osi OX)
        * @param f Dlugosc drugiej przekatnej w rombie (rownoleglej do osi OY)
        */
        Diamond (int x, int y, int e, int f): Diamond(Point(x,y),e,f){}

        /**
         * @brief Metoda wirtualna zwracajaca pole rombu
        */
        double area() const override;

        /**
         * @brief Metoda wirtulna sprawdzajaca, czy podany punkt znajduje sie w srodku rombu
        */
        bool isIn(int x, int y) const override;

        /**
         * @brief Metoda wirtualna zwracajaca dlugosc pierwszej przekatnej rombu
        */
        double diagonal1() const override;

        /**
         * @brief Metoda wirtualna zwracajaca dlugosc drugiej przekatnej rombu
        */
        double diagonal2() const override;

    private:
    Point center;///< Punkt przeciecia przekatnych rombu
    int d1; ///<Dlugosc pierwszej przekatnej rombu
    int d2; ///<Dlugosc drugiej przekatnej rombu
};