#pragma once

#include "File.h"
/**
*@class Klasa reprezentujaca symboliczne dowiazanie do pliku
*/
class Symlink: public Base
{
    public:
        Symlink();
        Symlink(const string& str, File* ptr);
        Symlink(const Symlink& other);
        
        /**
        *@brief Metoda wypisujaca nazwe pliku z indentacjami
        */
        void print(int n=0) const override;
        ~Symlink();
        /**
        *@brief Metoda zwracajaca typ pliku
        */
         virtual FSType getType() const override {return FSType::Symlink;}
        /**
        *@brief Metoda wypisujaca nazwe pliku ze sciezka
        */
        virtual void display(const string& str) const override 
        {
            cout << str << "/"; print();
        }
        private:
        File* link; ///<Wskaznik do pliku pelniacy funkcje symbolicznego dowiazania
};