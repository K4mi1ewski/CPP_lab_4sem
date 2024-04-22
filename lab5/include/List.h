/**
 * @file List.h
 * @brief Plik naglowkowy przechowujacy definicje klasy reprezentujaca liste wskaznikowa elementow o roznych typach.
*/

#pragma once

#include "Data.h"
#include <vector>
using namespace std;

/**
 * @class List
 * @brief Klasa ktora odpowiada za reprezentacje listy wskaznikowej.
*/
class List
{
    /**
     * @brief Operator strumieniowy wyjscia
     * @param os Strumien wyjscia
     * @param list Lista ktora ma zostac wypisana
     * @return Strumien wyjscia, na ktory ma zostac wypisana lista
    */
friend ostream& operator<< (ostream& os, const List& list);
public:
    enum insertion {Begin, End}; ///< Typ wyliczeniowy, ktorego wartosci sluza okresleniu w ktorym miejscu listy ma zostac dodany element
    
    /**
     *@brief Metoda pozwalajaca na dodanie nowego elementu do listy
     *@param data Dane, ktore maja zostac dodane jako nowy element
     *@param val Parametr ktory okresla czy dane maja zostac dodane na poczatku czy na koncu listy
     *@return Referencje na obiekt na ktorym zostala wywolana metoda (w celu umozliwienia lancuchowego wywolania funkcji).
     * Metoda tworzy nowy wskaznik z kopia danych, a nastepnie dodaje go na poczatku (val==Begin) lub (domyslnie) na koncu(val==End).
    */
    List& insert(const Data& data, insertion val=List::End);
    
    /**
     * @brief Metoda wypisuje liste na wyjscie.
     * @return Metoda nic nie zwraca (void).
    */
    void print() const;

    /**
     * @brief Bezargumentowy konstruktor listy (ustawia wskaznik head na nullptr)
    */
    List();

    /**
     * @brief Destruktor listy usuwajacy wszystkie elementy i zwalniajacy pamiec.
    */
    ~List();

    /**
     * @brief Konstruktor kopiujacy listy.
     * @param other Lista, z ktorej maja zostac skopiowane elementy.
    */
    List(const List& other);

    /**
     * @brief Operator przypisania (kopiujacy) dla listy.
     * @param other Lista z ktorej sa kopiowane wartosci
     * @return Operator zwraca referencje na obiekt dla ktorego zostal wywolany
    */
    List& operator= (const List& other);


    /**
    @brief Funkcja do odwracania liczb
    */
    List& reverse();

    /**
    *@brief Funkcja do znajdowania danego elementu w liscie i zwracajaca wskaznik na ten element
    */
    Data* find(const Data& data) const;
    /**
    *@brief Funkcja zwracajaca wektor wartosci rzeczywistych wyliczonych na podstawie wartosci danych listy
    */
    vector<double> eval() const;
 
    /**
    *@brief Funkcja kopiujaca elementy w zaleznosci od flagi
    */
    List copy_if(bool flag=true) const;




private:    
    /**
     * @struct ListNode
     * @brief Element listy wskaznikowej przechowujacy dane oraz wskaznik na kolejny element.
    */
    struct ListNode
    {
        Data* data; ///< Wskaznik na dane
        ListNode* next; ///< Wskaznik na kolejny element listy
        
        /**
         * @brief konstruktor dwuargumentowy dla elementu listy
         * @param d Pole danych
         * @param n Wskaznik na kolejny element
        */
        ListNode(Data* d, ListNode* n);
        
        /**
         * @brief Destruktor usuwajacy i zwalniajacy pamiec po danych.
        */
        ~ListNode();
    };
    ListNode* head; ///< Wskaznik na start listy
    
    /**
     * @brief Prywatna metoda sluzaca do usuwania danych w liscie i zwalniania pamieci.
    *  @return Metoda nic nie zwraca (void).
    */
    void clear();

    /**
     *@brief Prywatna metoda sluzaca do kopiowania elementow z listy.
     *@param otherlist Lista elementow do skopiowania
     *@return Wskaznik na nowo utworzona liste skopiowanych elementow. 
    */
    ListNode* copyList(ListNode* otherlist);
};
/* LIST_H */