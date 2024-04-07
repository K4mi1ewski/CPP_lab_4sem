#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* @brief struktura elementu tablicy asocjacyjnej
*/
struct assoc
    {
        string label;
        double price;
        
        /**
        *@brief Operator wyjscia sluzacy do wypisania danych struktury
        */
        friend ostream& operator<< (ostream& os, const assoc& obj);
    };

class TAssoc
{
public:
    /**
    * @brief operator wyjscia dla klasy TAssoc
    * @param os operator strumienia wyjscia
    * @param obj stala referencja do tablicy asocjacyjnej
    * Operator sluzy do wypisywania elementow tablicy
    * @return Operator strumienia wyjscia
    */
    friend ostream& operator<< (ostream& os, const TAssoc& obj);
    
    /**
    * @brief Metoda dodajaca kolejny element do tablicy
    * @param lbl Klucz obiektu do wpisania do tablicy
    * @param val Wartosc obiektu do wpisania do tablicy
    * @return Referencja do obiektu na ktorym wywolano metode
    */
    TAssoc& insert(const string& lbl, double val);
    
    
    /**
    *@brief staly operator indeksowania za pomoca kluczy-napisow dla tablicy asocjacyjnej
    *@param lbl Klucz do wyszukania
    *@return Stala wartosc produktu przypisana do klucza lub zero gdy obiekt o podanym kluczu nie istnieje
    */
    const double operator[](const string& lbl) const;
    
    /**
    *@brief operator indeksowania za pomoca kluczy-napisow dla tablicy asocjacyjnej
    *@param lbl Klucz do wyszukania
    *Operator dodaje element i ustawia jego wartosc ceny na "0" gdy element o podanym kluczu nie znajdowal sie wczesniej w tablicy
    *@return Referencja do wartosci produktu o danym kluczu
    */
    double& operator[](const string& lbl);
    
    /**
    * @brief operator indeksowania dla tablicy asocjacyjnej za pomoca liczb calkowitych
    * @param num Indeks obiektu do wyszukania
    * @return Obiekt typu assoc 
    */
    assoc& operator[](int num);

    /**
    *@brief Metoda sumujaca ceny wszystkich produktow w tablicy asocjacyjnej
    *@return suma cen produktow
    */
    double sum() const;

    /**
    *@brief Metoda sprawdzajaca czy produkt o danym kluczu znajduje sie w tablicy
    *@param lbl klucz produktu do wyszukania
    *@return True gdy element o podanym kluczu znajduje sie w tablicy, false w przeciwnym razie
    */
    bool contains (const string lbl) const;
    
    /**
    *@brief Operator przeniesienia
    *@param other obiekt do przeniesienia
    *@return referencja do tablicy asocjacyjnej
    */
    TAssoc& operator=(TAssoc&& other);

    /**
    *@brief Operator przypisania
    *@param other Obiekt do skopiowania
    *@return referencja do tablicy asocjacyjnej
    */
    TAssoc& operator=(const TAssoc& other);
    
    /**
    *@brief Konstruktor kopiujacy 
    *@param other Obiekt do skopiowania
    */
    TAssoc(const TAssoc& other);
    /**
    *@brief Destruktor
    */
    ~TAssoc();
    /**
    *@brief Konstruktor bezargumentowy
    */
    TAssoc();
private:
    /**
    * Wektor struktor sluzacy jako tablica asocjacyjna 
    */
    vector<assoc> tab;    
};