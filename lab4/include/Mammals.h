#pragma once
#include "Mammal.h"
/**
*@brief klasa reprezentujaca psa
*/
class Dog: public Mammal
{ 
  public:
  Dog(const string name, int wiek, const string sex, int wlosy):
  Mammal(name, wiek, sex, wlosy){type_ += "->pies";}
  /**
  @brief Metoda odpowiedzialna za stanie na tylnych lapach przez psa
  */
  void fetch() const
  {
    cout << "Stoje na tylnych lapach."<<endl;
  }
  /**
  *@brief metoda wirtualna odpowiedzialna za szczekanie psa
  */
  void makeSound() const override
  {
    cout <<"Hau hau!"<<endl;
  }
};
/**
*@brief Klasa reprezentujaca kota
*/
class Cat: public Mammal
{
  public:
    Cat(const string name, int wiek, const string sex, int wlosy):
    Mammal(name, wiek, sex, wlosy){type_ += "->kot";}
    /**
    *@brief metoda odpowiedzialna za drapanie kota
    */
    void scratch() const
    {
      cout<<"Drapie pazurami meble"<<endl;
    }
    /**
    *@brief wirtualna metoda odpowiedzialna za miauczenie kota
    */
    void makeSound() const override
    {
      cout << "Miau miau!" << endl;
    }
};