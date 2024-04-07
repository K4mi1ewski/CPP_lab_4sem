#pragma once
#include "Bird.h"
/**
*@brief klasa reprezentujaca papuge
*/
class Parrot: public Bird
{   
    public:
    Parrot(const string name, int wiek, const string sex, const string color):
    Bird(name, wiek, sex, color) {type_+="->papuga";}
    /**
    *@brief Metoda odpowiedzialna za gadanie papugi
    */
    void speak() const
    {
        cout << "Potrafie gadac."<<endl;
    }
    /**
    *@brief Metoda wirtualna odpowiedzialna za blablanie papugi
    */
    void makeSound() const override
  {
    cout <<"Bla bla bla"<<endl;
  }
};

/**
*@brief klasa reprezentujaca kaczke
*/
class Duck: public Bird
{   
    public:
    Duck(const string name, int wiek, const string sex, const string color):Bird(name, wiek, sex, color) {type_+="->kaczka";}
    /**
    *@brief metoda odpowiedzialna za plywanie kaczki
    */
    void swim() const
    {
        cout << "Potrafie plywac" <<endl;
    }
    /**
    *@brief metoda odpowiedzialna za (nie)latanie kaczki
    */
    void fly () const override
    {
        cout <<"Nie umiem latac" <<endl;
    }
    /**
    *@brief Metoda odpowiedzialna za kwaczenie kaczki
    */
    void makeSound() const override
    { 
        cout <<"Kwa kwa kwa!"<<endl;
    }
    
};