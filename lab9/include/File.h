#pragma once
#include "Base.h"

/**
*@class Klasa reprezentujaca zwykly plik
*/
class File: public Base
{
    public:
    
        File();
        ~File(){}
        File(const string& str, int val);
        /**
        *@brief Konstruktor kopiujacy
        */
        File (const File& other);
        /**
        *@brief Metoda zwracajaca wielkosc pliku w kB
        */
        int getSize() {return size;}
        /**
        *@brief Metoda zmieniajaca nazwe pliku
        */
        void rename(const string& str);

        /**
        *@brief Metoda wirtualna wypisujaca nazwe pliku z indentacjami
        */
        void print(int n=0) const override;

        /**
        *@brief Zaprzyjaznienie klasy Symlink
        */
        friend class Symlink;

        /**
        *@brief Metoda zwracajaca typ pliku
        */
         virtual FSType getType() const override {return FSType::File;}
        
        /**
        *@brief Metoda wypisujaca nazwe pliku ze sciezka
        */
        virtual void display(const string& str) const override 
        {
            cout << str << "/"; print();
        }
    private:
        int size; ///<Rozmiar pliku
};
