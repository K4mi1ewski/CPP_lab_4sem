#pragma once
#include "Animal.h"
/**
*@brief Klasa pochodna, reprezentuje ptaki
*/
class Bird: public Animal
{
    public:
    Bird(const string name, int wiek, const string sex, const string color):
    Animal(name,wiek,sex), color_(color){type_+="->ptak";}
    //metoda wirtualna - wydawanie dzwieku
    void makeSound() const override
    {
        cout<<"Ptasi swiergot!"<<endl;
    }
    //metoda odpowiedzialna za lot ptaka
    virtual void fly() const
    {
        cout << "Fruwam wysoko!"<<endl;
    }
    //metoda wirtualna - wypisuje dane ptaka
    void print() const override
    {
    Animal::print();
    cout <<", upierzenie: "<< color_;    
    }
    //metoda wirtualna - rozmnazanie
    void reproduce() const override
    {
        if (sex_ == "plec meska")
            cout << "Zaplodnilem samice."<<endl;
        else if (sex_ == "plec zenska")
            cout << "Znioslam jaja."<<endl;
    }

    protected:
    string color_; ///<Zmienna oznaczajaca kolor ptaka
};