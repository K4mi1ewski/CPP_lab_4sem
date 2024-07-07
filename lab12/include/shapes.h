#pragma once 
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::setw;

/**
 * @class Klasa bazowa dla ksztaltow
*/
class Shape
{
    public:
    
    

    /**
     * @brief Metoda wirtualna do sprawdzania, czy dany punkt znajduje sie w jej srodku
     * @param x Wspolrzedna x punktu do sprawdzenia
     * @param y Wspolrzedna y punktu do sprawdzenia
    */
    virtual bool isIn (int x, int y) const = 0;
    Shape* get() {return this;}
};

class BasicShape: public Shape
{
public:
/**
     * @brief Metoda wirtualna do obliczania pola figury
    */
virtual double area() const = 0;
};


/**
 * @class Klasa bazowa dla ksztaltow posiadajacych przekatna
*/
class HasDiagonal: public BasicShape
{
    public:
    /**
     * @brief Metoda wirtualna zwracajaca wartosc pierwszej przekatnej figury
    */
    virtual double diagonal1() const = 0;

    /**
     * @brief Metoda wirtualna zwracajaca wartosc drugiej przekatnej figury
    */
    virtual double diagonal2() const = 0;
};

/**
 * @class Klasa reprezentujaca punkt
*/
class Point
{
    public:
    /**
     * @brief Konstruktor dwuargumentowy
     * @param x Wspolrzedna x punktu
     * @param y Wspolrzedna y punktu
    */
    Point(int x, int y):x_(x), y_(y) {}
    /**
     * @brief Metoda zwracajaca wspolrzedna x
    */
    int x() const {return x_;} 
    /**
     * @brief Metoda zwracajaca wspolrzedna y
    */
    int y() const {return y_;}
    private:
    int x_; ///<Wspolrzedna x punktu
    int y_; ///<Wspolrzedna y punktu
};