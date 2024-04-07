#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
* @brief klasa bazowa oznaczajaca zwierzel 
*/
class Animal {

protected:
    string name_;///< imie
    int age_;///<wiek
    string sex_;///<plec
    string type_;///<typ zwierzecia(gatunek)

public:
/**
*@brief konstruktor trojargumentowy
*/
    Animal(const string& name, int age, const string& sex) : name_(name), age_(age), sex_(sex) 
    {
        counter++;
        type_ = "zwierze";
    }
    /**
    *@brief metoda wirtualna - wydawanie dzwieku
    */
    virtual void makeSound() const=0;
    /**
    *@brief metoda wirtulna - rozmnazanie
    */
    virtual void reproduce() const=0;
    /**
    *@brief metoda odpowiedzialna za usypianie zwierzat
    */
    void sleep() const
    {
        delete this;
    }
    
    /**
    *@brief Metoda wirtualna odpowiada za wypisywanie wszystkich informacji dotyczacych zwierzecia
    */
    virtual void print() const
        {
            cout << "Jestem " << name_ << ", " << type_ << ", mam " << age_ << " miesiecy, " << sex_;
        }
    /**
    *@brief Destruktor, zmniejsza licznik zwierzat w zoo
    */
    virtual ~Animal() 
        {
        counter--;
        }
    /**
    *@brief operator strumienia wyjscia, odpowiada za wypisywanie za pomoca metody print
    */
    friend ostream& operator << (ostream& os, const Animal& obj)
    {
        obj.print();
       return os;
    }
    /**
    *@brief metoda zwraca wartosc licznika - ilosc zwierzat w zoo
    */
     static int getCount() 
    {
        return counter;
    }
    private:
    static int counter;///<licznik zwierzat 

};

int Animal::counter=0;

