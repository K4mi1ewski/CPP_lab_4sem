/**
 * @file Data.h
 * @brief Plik naglowkowy zawierajacy definicje abstrakcyjnej klasy Data oraz jej klas pochodnych Fraction oraz StringData.
*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * @class Data
 * @brief Definicja abstrakcyjnej klasy Data
 * 
 * Klasa Data sluzy jako interfejs dla stworzenia klas reprezentujacych dane przechowywane w liscie.
*/
class Data
{
    public:
    /**
    * @brief Wirtualna metoda print - sluzy do wypisania danych.
    * @return Metoda nic nie zwraca (void).
    */
    virtual void print() const = 0;
    /**
    *@brief Wirtualna metoda clone - sluzy do tworzenia oraz zwracania nowych wskaznikow w celu skopiowania danych. 
    *@return Metoda zwraca wskaznik typu Data - moze on reprezentowac dane jednej z klas pochodnych.
    */
    virtual Data* clone() const = 0;

    /**
    *@brief Wirtualna metoda eval  do wyznaczania wartosci na podstawie danych
    *@return liczba rzeczywista
    */
    virtual double eval() const = 0;

    virtual bool check(const Data& data) const = 0;
    virtual ~Data(){}

};


/**
 * @class Fraction
 * @brief Klasa przechowujace dane reprezentujace licznik i mianownik ulamka
*/
class Fraction: public Data
{
    public:
        /**
         * @brief Konstruktor dwuargumentowy klasy Fraction
         * @param n licznik ulamka
         * @param d mianownik ulamka
        */
        Fraction(int n, int d=1);

        /**
         * @brief Przeciazona metoda print sluzaca do wypisywania ulamka.
        */
        void print() const override;

        /**
         * @brief Przeciazona metoda clone sluzaca do zwracania kopii danych ulamka.
        */
        Fraction* clone() const override;

        double eval() const override;

        bool check(const Data& data) const override
        {
            const Fraction* ptr = dynamic_cast<const Fraction*>(&data);
            return (ptr!= nullptr) && (nominator == ptr-> nominator) && (denominator==ptr->denominator);
        }
        ~Fraction(){}
    private:
        
        int nominator; ///< licznik ulamka
        int denominator; ///< mianownik ulamka
};

/**
 * @class StringData
 * @brief Klasa przechowujaca napis jako dane.
*/
class StringData: public Data
{
    public:
        /**
         * @brief Jednoargumentowy konstruktor StringData 
         * @param str Napis do przechowania jako dane.
        */   
        StringData(const string& str);

        /**
         * @brief Przeciazona metoda print sluzaca do wypisania tekstu.
        */
        void print() const override;

        /**
         * @brief Przeciazana metoda clone sluzaca do zwracania kopii danych tekstu.
        */
        StringData* clone() const override;

        double eval() const override;
        bool check(const Data& data) const  override
        {
            const StringData* ptr = dynamic_cast<const StringData*>(&data);
            return (ptr!=nullptr) && (text == ptr->text);
        }
        ~StringData(){}
    private:
        string text; ///< Dane tekstowe        
};

/**
*@class klasa reprezentujaca znak jako dane
*/
class CharData: public Data
{
public:
/**
* @brief konstruktor jednoargumentowy
* @param znak Znak do inicjalizacji danych
*/
    CharData(const char znak);
    /**
    *@brief Przeciazona metoda do wypisywania
    */
    void print() const override;
    /**
    *@brief Przeciazona metoda do kopiowania danych
    */
    CharData* clone() const override;
    /**
    *@brief Przeciazona metoda do wyznaczania wartosci na podstawie danych
    */
    double eval() const override;

    bool check(const Data& data) const  override
        {
            const CharData* ptr = dynamic_cast<const CharData*>(&data);
            return (ptr!=nullptr) && (sign == ptr->sign);
        }
    ~CharData(){}
private:
    char sign; ///< znak jako dane
};
/* DATA_H */