#pragma once
#include "shapes.h"

/**
 * @class Klasa reprezentujaca prostokat
*/
class Rectangle: public HasDiagonal
{
    public:
    /**
     * @brief Konstruktor czteroargumentowy
     * @param x1 Wspolrzedna x pierwszego punktu
     * @param y1 Wspolrzedna y pierwszego punktu
     * @param x2 Wspolrzedna x drugiego punktu
     * @param y2 Wspolrzedna y drugiego punktu
    */
    Rectangle(int x1, int y1, int x2, int y2): p1(x1,y1), p2(x2,y2){}

    /**
     * @brief Konstruktor dwuargumentowy
     * @param point1 Pierwszy punkt opisujacy prostokat
     * @param point2 Drugi punkt opisujacy prostokat
    */
    Rectangle (const Point& point1, const Point& point2): p1(point1),p2(point2){}
   
    /**
     * @brief Metoda wirtualna zwracajaca dlugosc pierwszej przekatnej
    */
    double diagonal1() const override;

    /**
     * @brief Metoda wirtualna zwracajaca dlugosc drugiej przekatnej
    */
    double diagonal2 () const override;

    /**
     * @brief Metoda wirtualna zwracajaca pole prostokata
    */
    double area() const override;

    /**
     * @brief Metoda wirtualna sprawdzajaca, czy podany punkt nalezy do prostokataa
     * @param x Wspolrzedna x punktu do sprawdzenia
     * @param y Wspolrzedna y punktu do sprawdzenia
    */
    bool isIn (int x, int y) const override;
    private:
    Point p1, p2; ///< Punkty opisujace polozenie prostokata

};