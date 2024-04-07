#pragma once
#include "Animal.h"

/**
*@brief Klasa pochodna, tworzy obiekty reprezntujace ssaki
*/
class Mammal:public Animal
{
    public:
    Mammal(const string name, int wiek, const string sex, int wlosy): Animal(name, wiek, sex), wlosy_(wlosy)
    {
        type_ += "->ssak";
    }
    //metoda wirtualna przeladowana
    void reproduce() const override
    {
        if (sex_ == "plec meska")
        {
            cout << "Zaplodnilem samice!"<<endl;
        }
        else if (sex_ == "plec zenska")
        {
            cout << "Jestem w ciazy!"<<endl;
        }
    }
    //metoda wirtualna przeladowana
    void print() const override
    {
    Animal::print();
    cout<<", pokrycie skory: "<< (wlosy_ ? "siersc" :"wlosy");    
    }

    
    protected:
    int wlosy_;///<Zmienna mowiaca o tym czy ssak posiada wlosy(0) czy siersc(1)
};