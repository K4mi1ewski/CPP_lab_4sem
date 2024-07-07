#pragma once
#include "shapes.h"
#include <iostream>
using namespace std;
/**
 * @class Klasa odpowiedzialna za rysowanie kształtów na zadanym obszarze
 * 
*/
class Stage{
public:
/**
 * @brief Konstruktor dwuargumentowy
 * @param width Szerokosc zakresu
 * @param height Wysokosc zakresu
*/
    Stage(size_t width, size_t height): w(width),h(height){}
    
    /**
     * @brief Metoda rysujaca ksztalty za pomoca gwiazdek oraz spacji
     * @param shape Wskaznik do obiektu ktory ma zostac narysowany
     * @param os Strumien wyjsciowy
    */
    void drawShape(const Shape* shape, ostream& os) const;

private:
    size_t w; ///< Szerokosc zakresu
    size_t h; ///< Wysokosc zakresu

};