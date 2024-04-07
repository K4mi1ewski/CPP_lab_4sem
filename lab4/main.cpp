/*
Tematem zadania jest przećwiczenie dziedziczenia wielokrotnego, polimorfizmu w celu agregacji części wspólnych, a tym samym redukcji kodu zgodnie z zasadą DRY (Don't Repeat Yourself)
Założymy sobie mini Zoo złożone z różnych zwierząt. Każde zwierzę ma imię, wiek, wydaje jakiś dźwięk, rozmnaża się i może zostać uśpione.
Klasa Animal powinna posiadać wirtualne metody, ale nie jest klasą abstrakcyjną, powinna agregować wspólne składowe i metody.
Zwierzę (Animal) dzielimy na:
- Mammal - ssaki (posiadają sierść albo włosy, samica zachodzi w ciążę)
- Bird - ptaki (posiadają upierzenie w określonym kolorze, samice znoszą jaja)
Ponadto mamy psa, kota, kaczkę i papugę, każde ze zwierząt dziedziczy cechy gatunku, do którego należy, wydaje charakterystyczny dźwięk i posiada dodatkowe cechy:
- pies potrafi aportować,
- kot drapie meble
- kaczka potrafi pływać, ale nie umie latać 
- papuga potrafi gadać.

Ponadto liczymy wszystkie zwierzęta umieszczone w ZOO, a jeśli któreś z nich choruje, to go usypiamy (niszczymy obiekt).

WSKAZÓWKI:
- Napis typu zwierze->ptak->kaczka wskazuje hierarchię dziedziczenia, twórz za pomocą konkatenacji napisów.
- Klasy są krótkie, ale plików jest dużo, można zdefiniować je w pliku .h
- Większość metod nie ma argumentów, stosuj krótkie komentarze ///@brief
- Wygeneruj dokumentację i przeslij katalog HTML
- Nie zapomnij o wykorzystywaniu konstruktorów klas macierzystych do tworzenia obiektów.
- Żeby zdefiniować operatory << warto się posłużyć metodą drukującą, ew. mozna wykorzystać rzutowanie, aby nie powielać kodu.

Pakujemy jak zawsze bez katalogu nadrzędnego, dodajemy tylko katalog HTML.
Proszę sprawdzić czy nie ma wycieków pamięci za pomocą valgrind (make check).
*/

#include <iostream>
#include "Animal.h"
#include "Bird.h"
#include "Mammal.h"
#include "Mammals.h" // Dog i Cat
#include "Birds.h"  // Duck i Parrot

int main() {
  const std::string male= "plec meska";
  const std::string female= "plec zenska";
  // imie, wiek, płeć, kolor upierzenia
  const Bird * bird = new Bird("Ptaszek", 2, "plec nieznana", "szare");
  const Parrot * parrot = new Parrot("Plotkarz", 2, male, "kolorowe");
  const Duck* duck = new Duck("Kwaczka", 5, female, "zolte");
// imie, wiek, płeć, siersc=1, wlosy=0
  const Dog * dog = new Dog("Burek", 3, male, 1); 
  const Cat * cat = new Cat("Kicia", 5,  female, 0);

  std::cout << "Liczba zwierzat w mini ZOO: " << Animal::getCount() << std::endl;
  bird->makeSound(); // Ptasi swiergot!
  bird->fly();  // Fruwam wysoko!
  std::cout <<  *bird << std::endl; // Jestem Ptaszek, zwierze->ptak, mam 2 miesiecy, plec nieznana, upierzenie: szare
  
  duck->makeSound(); //Kwa Kwa!
  duck->reproduce(); // Znioslam jaja.
  duck->fly(); // Nie umiem latac.
  duck->swim(); // Potrafie plywac.
  std::cout <<  *duck << std::endl; // Jestem Kwaczka, zwierze->ptak->kaczka, mam 5 miesiecy, plec zenska, upierzenie: zolte
  
  std::cout <<  *parrot << std::endl; //Jestem Plotkarz, zwierze->ptak->papuga, mam 2 miesiecy, plec meska, upierzenie: kolorowe
  parrot->makeSound(); // Bla Bla Bla
  parrot->speak(); // Potrafie gadac.
  parrot->reproduce(); // Zaplodnilem samice.
  
  std::cout << std::endl << *cat << std::endl; // Jestem Kicia, zwierze->ssak->kot, mam 5 miesiecy, plec zenska, pokrycie skory: wlosy
  cat->makeSound(); // Miau Miau!
  cat->reproduce(); // Jestem w ciazy.
  cat->scratch(); // Drapie pazurami meble
  
  std::cout << *dog << std::endl; // Jestem Burek, zwierze->ssak->pies, mam 3 miesiecy, plec meska, pokrycie skory: siersc
  dog->makeSound(); // Hau Hau!
  dog->fetch(); // Stoje na tylnych lapach.
  dog->reproduce(); // Zaplodnilem samice
  
  // ZARAZA! Usypianie zwierząt chorych
  dog->sleep(); //likwidujemy obiekty
  cat->sleep();
  bird->sleep();

  std::cout << "Liczba zwierzat po uspieniu: " << Animal::getCount() << std::endl;
  delete duck;
  delete parrot;
  
  return 0;
}

/* Oczekiwany wynik:

Liczba zwierzat w mini ZOO: 5
Ptasi swiergot
Fruwam wysoko.
Jestem Ptaszek, zwierze->ptak, mam 2 miesiecy, plec nieznana, upierzenie: szare
Kwa Kwa Kwa!
Znioslam jaja.
Nie umiem latac.
Potrafie plywac.
Jestem Kwaczka, zwierze->ptak->kaczka, mam 5 miesiecy, plec zenska, upierzenie: zolte
Jestem Plotkarz, zwierze->ptak->papuga, mam 2 miesiecy, plec meska, upierzenie: kolorowe
Bla Bla Bla
Potrafie gadac.
Zaplodnilem samice.

Jestem Kicia, zwierze->ssak->kot, mam 5 miesiecy, plec zenska, pokrycie skory: wlosy
Miau Miau!
Jestem w ciazy.
Drapie pazurami meble.
Jestem Burek, zwierze->ssak->pies, mam 3 miesiecy, plec meska, pokrycie skory: siersc
Hau Hau!
Stoje na tylnych lapach.
Zaplodnilem samice.
Liczba zwierzat po uspieniu: 2


*/

