#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/**
*@enum typ wyliczeniowy okreslajacy rodzaj pliku
*/
enum class FSType {File, Dir, Symlink};

/**
*@class klasa bazowa sluzaca za interfejs dla innych rodzajow plikow
*/
class Base
{
  public:
  /**
  *@brief Konstruktor domyslny
  */
    Base();

    /**
    *@brief Konstruktor jednoargumentowy do zainicjowania nazwy
    */
    Base(const string& n);

    /**
    *@brief Metoda zwracajaca nazwe pliku
    */
    string getname () const {return name;}
    
    /**
    *@brief Metoda wirtualna sluzaca do wypisywania
    *@param n Liczba indentacji
    */
    virtual void print (int n = 0) const;
    
    /**
    *@brief Metoda wirtualna zwracajaca typ pliku
    */
    virtual FSType getType() const = 0;

    /**
    *@brief Metoda wirtualna sluzaca do wypisywania lokalizacji pliku ze sciezka
    *@param str Sciezka do pliku
    */
    virtual void display(const string& str) const = 0;

    /**
    *@brief Metoda ktora sprawdza czy podany napis jest rowny nazwie pliku
    *@param str napis do sprawdzenia
    */
    bool check(const string& str);
    virtual ~Base(){}
  protected:
    string name; ///<Nazwa pliku
};