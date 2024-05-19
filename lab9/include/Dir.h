#pragma once
#include "Base.h"

/**
*@class Klasa reprezentujaca katalogi
*/
class Dir: public Base
{
    public:
        Dir();
        Dir(const string& n);
        Dir(const Dir& other);
        /**
        *@brief Operator dodajacy plik do katalogu 
        *@param ptr Wskaznik na plik ktory ma zostac dodany
        */
        Dir& operator+= (Base* ptr);

        /**
        *@brief Operator usuwajacy plik z katalogu
        *@param name Nazwa pliku ktory ma zostac usuniety
        */
        void operator-= (const string& name);

        /**
        *@brief Metoda wypisujaca nazwe katalogu oraz jego zawartosc z indentacjami
        */
        void print(int n=0) const override;
        /**
        *@brief Metoda dodajaca kopie pliku do katalogu
        *@param ptr Plik ktory ma zostac skopiowany
        */
        void copy(Base* ptr);

        /**
        *@brief Metoda wypisujaca pliki znajdujace sie w katalogu o okreslonej wielkosci
        *@param size Rozmiar, ktory ma byc mniejszy niz rozmiary wszystkich wypisanych plikow w katalogu
        */
        void printFilesGreaterThanSize(int size);

        /**
        *@brief Metoda zwracajaca katalog o podanej nazwie
        *@param str Nazwa szukanego katalogu
        */
        Dir* getDir(const string& str);
        /**
        *@brief Metoda zwracajaca plik o podanej nazwie
        *@param str Nazwa szukanego pliku
        */
        Base* get (const string& str);


        ~Dir();
        /**
        *@brief Metoda zwracajaca typ pliku
        */
        virtual FSType getType() const override {return FSType::Dir;}
        /**
        *@brief Metoda wypisujaca katalog wraz ze sciezka
        */
        virtual void display(const string& str) const override 
        {
            cout << str << "/" << getname() << " (dir)" << endl;
        }

        /**
        *@brief Metoda  rekurencyjnie wypisujaca pliki podanego typu, z maksymalnym zaglebieniem
        *@param type Typ pliku do wypisania
        *@param maxdeep Maksymalna glebokosc do szukania plikow w podkatalogach
        *@param deep Aktualna glebokosc wypisywanego katalogu
        *@param str Sciezka do wypisywanego aktualnie pliku
        */
        void printByType(FSType type, int maxdeep=100, int deep=0, const string& str="");
        
        /**
        *@brief Metoda wypisujaca jedynie podkatalogi na podana glebokosc
        *@param deep podana glebokosc do wypisania podkatalogow
        */
        void printDirs(int deep);
    private:
        vector<Base*> lista; ///< Lista plikow w katalogu
        /**
        *@brief Zaprzyjazniona metoda do wypisywania plikow i dowiazan symbolicznych
        */
        friend void printFiles(Dir*); 
    
    friend ostream& operator<< (ostream& os, const Dir& obj);
};

void printFiles(Dir* directory);