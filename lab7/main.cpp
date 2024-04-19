/*
  Celem zadania jest przećwiczenie dynamic_cast na przykładzie systemu plików składającego się z klas:
  - katalog - ma nazwę i wektor podrzędnych składników
  - plik - ma nazwę i rozmiar (podawany w nawiasach
  - link symboliczny - plik o rozmiarze pustym zawierający link do innego pliku (dla uproszczenia darujemy sobie katalogi).
   
   UWAGA:
  * Aby zapewnic wypisywanie z wcięciami, metoda print powinna posiadać argument informujacy, ile spacji potrzeba wypisac przed nazwą (indentacja).
  * Podczas kopiowania przydana bedzie polimorficzna metoda kopiujaca wywoływana przez copy.
  * Proszę pamiętać o zwolnieniu pamieci w destruktorze.
 */
 
#include <iostream>
#include "Dir.h"
#include "File.h"
#include "Symlink.h"

int main() {
  std::cout << "------- Etap 1. Katalogi -------\n";
  Dir *top = new Dir(".");
  Dir *home = new Dir("home");
  *top += home; // dodajemy do kat top podkatalog
  Dir *stud1 = new Dir("stud1");
  *home += stud1;
  Dir *stud2 = new Dir("stud2");
  *home += stud2;  
  top->print();

  std::cout << "\n------- Etap 2. Pliki -------\n";
  File* img1 = new File ("img1.jpg", 2020);
  File* img2 = new File ("img2.jpg", 2021);
  *stud1+=img1; 
  *stud1+=img2;
  Dir* work = new Dir("work");
  File* f1 = new File ("main.h",150);
  *work += f1;
  Symlink* slink = new Symlink ("symlink", f1);
  *work += slink;
  *stud1 += work;
  std::cout << *home <<std::endl;
  
  std::cout << "------- Etap 3. Kopiowanie -------\n";
  stud2->copy(top->getDir("work")); // trzeba koniecznie zrobic kopie
  if (stud1->getDir("img1.jpg"))
    std::cout << "**** TO NIE POWINNO SIE WYPISAC ****\n";

    stud2->copy(stud1->get("img1.jpg"));
    *work += new Dir("tmp");
    Dir *tmp = static_cast<Dir*>(top->getDir("tmp"));
    Dir* cpp = new Dir ("cpp");


    *tmp += cpp;
    f1->rename("main.cpp");
    std::cout << *(stud1->getDir("work"));
    // //usuwanie dla chętnych w domu
    // *work -= "tmp";
    // *work -= "proj.h";

    std::cout << "\n------ Cale drzewo -------" << std::endl;
    std::cout << *top;
    std::cout << "Tylko pliki: ";
    printFiles(stud2);
    std::cout << std::endl;
    delete top;

}

/* oczekiwany wynik 
------- Etap 1. Katalogi -------
. (dir)
  home (dir)
    stud1 (dir)
    stud2 (dir)

------- Etap 2. Pliki -------
home (dir)
  stud1 (dir)
    img1.jpg (2020)
    img2.jpg (2021)
    work (dir)
      main.h (150)
      symlink -> main.h
  stud2 (dir)

------- Etap 3. Kopiowanie -------
work (dir)
  main.cpp (150)
  symlink -> main.cpp
  tmp (dir)
    cpp (dir)

------ Cale drzewo -------
. (dir)
  home (dir)
    stud1 (dir)
      img1.jpg (2020)
      img2.jpg (2021)
      work (dir)
        main.cpp (150)
        symlink -> main.cpp
        tmp (dir)
          cpp (dir)
    stud2 (dir)
      work (dir)
        main.h (150)
        symlink -> main.cpp
      img1.jpg (2020)
Tylko pliki: main.h symlink img1.jpg 
 */ 