/*
  Pamiętacie zadanie z lab. 7 dotyczące klas reprezentujących system plików? Dzisiaj oczyścimy kod i dopiszemy sobie kilka funkcji:
  - Operator -= - czyli usuwamy całą gałąź drzewa (to było zadanie dodatkowe - domowe).
  - printFilesGreaterThanSize - wypisz pliki, których rozmiar jest większy od podanego (zastosuj rekurencyjne wyrażenie lambda).
  - printByType - podajemy typ i wypisujemy wszystkie elementy o podanym typie. Możemy również podać głębokość wyświetlania. Również zastosuj wyrażenie lambda
  UWAGA - zmiemił się sposób wypisywania elementu. Aby zapewnić wypisywanie ze ścieżką, warto dodać nową metodę wirtualną typu print (np display), która przechowuje beżącą ścieżkę.
  - printDirs - specyficzne wywołanie metody printByType.

Proszę zrobić porządek w kodzie - podział na pliki .h i .cpp.
Można pracować na poprzedniej wersji lub wersji dopracowanej w domu.
 
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
  std::cout << *(stud1->getDir("work")) << std::endl;
  
  // usuwanie tym razem obowiązkowe
    std::cout << "------- Etap 4. Kasowanie -------\n";
    *work -= "tmp"; //zakładamy, że plik czy katalog znajduje się w tym katalogu, wskazówka, zastosuj erase(begin()+iterator)
    *stud1 -= "img1.jpg";
    std::cout << *top;
  
   std::cout << "\n--- Tylko pliki (zwykle i linki symboliczne): ---\n";
   printFiles(top);
  std::cout << std::endl;
  
  std::cout << "\n------ Pliki > 200kB -------\n";
  top->printFilesGreaterThanSize(200); // link symboliczny tworzony w programie ma wielkość 0
  
  std::cout << "\n------ Same pliki zwykle -------\n";
  top -> printByType(FSType::File); //poziom domyślnie ustawiony na 100

   std::cout << "\n--- Pierwszy poziom katalogow ----\n";
   stud1->printByType(FSType::Dir, 1);
  std::cout << "\n--- Trzy poziomy katalogow ---\n";
  top->printDirs(3); // to samo co top->printByType(FSType::Dir, 3);
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

------- Etap 4. Kasowanie -------
. (dir)
  home (dir)
    stud1 (dir)
      img2.jpg (2021)
      work (dir)
        main.cpp (150)
        symlink -> main.cpp
    stud2 (dir)
      work (dir)
        main.h (150)
        symlink -> main.cpp
      img1.jpg (2020)

--- Tylko pliki (zwykle i linki symboliczne): ---
img2.jpg main.cpp symlink main.h symlink img1.jpg 

------ Pliki > 200kB -------
img2.jpg (2021)
img1.jpg (2020)

------ Same pliki zwykle -------
./home/stud1/img2.jpg (2021)
./home/stud1/work/main.cpp (150)
./home/stud2/work/main.h (150)
./home/stud2/img1.jpg (2020)

--- Pierwszy poziom katalogow ----
stud1/work (dir)

--- Trzy poziomy katalogow ---
./home (dir)
./home/stud1 (dir)
./home/stud1/work (dir)
./home/stud2 (dir)
./home/stud2/work (dir)
 */ 