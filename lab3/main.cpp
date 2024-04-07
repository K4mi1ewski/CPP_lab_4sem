/* Calem zadania jest przećwiczenie operatorów ++ oraz operatora() i jego wykorzystania w połączeniu z std::function.

 Proszę napisać:
 - klasę Text, ktora przechowuje tekst,
 - klasę TextManipulator, ktora przechowuje listę obiektów funkcyjnych dokonujących operacji modyfikujących tekst obiektu Text,

 Oraz klasy, które mają zdefiniowany operator() dokonujący operacji
 na tekście: 
 - Append - dodaje ustalony tekst na końcu tekstu przechowywanego przez obiekt Text
 - Insert - dodaje ustalony tekst na początku tekstu przechowywanego przez obiekt Text
 - Replace - zastępuje tekst przechowywany przez obiekt Text innym.
 operacje te nie zmieniają obiektu Text, lecz tworzą nowy napis.
 Ich definicje można umieścić je w tym samym pliku Operations.h

 UWAGA: zalecane użycie std::vector oraz std::string.

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. 
Zadanie proszę wysłać w postaci archiwum zip albo tgz, w którym mają znaleźć się:
dwa katalogi include i src (z zawartością) oraz pliki main.cpp i CMakeLists.txt 
bez żadnych katalogów nadrzędnych (zwłaszcza anonimowych typu lab1).
Można spakować z linii poleceń:
zip -r G5_Nazwisko.zip include src main.cpp CMakeLists.txt 
lub
tar czvf G5_Nazwisko.tgz include src main.cpp CMakeLists.txt 
albo utworzyć archiwum za pomocą menadżera plików, zaznaczając wszystkie potrzebne pliki.
NIE WYSYŁAMY katalogu build, html, latex. 

*/

#include "TextManipulator.h"
#include "Operations.h"
#include "Text.h"
#include <iostream>

int main()
{
  std::cout << "===== Test inkrementacji: =====" << std::endl;
  Text t("Number*");
  std::cout << t++ << std::endl; 
  std::cout << t << std::endl; 
  std::cout << ++t << std::endl; 

  std::cout << "===== Test operacji na tekscie: =====" << std::endl;
  const Text t1("Jeden");
  std::cout <<t1 << std::endl; 
  
  Operations::Append appendTo(" dwa");
  Operations::Insert insertBefore("zero ");
  Operations::Replace replace("trzy");
  
  const Text t2 = appendTo(t1);
  std::cout << t2 << std::endl; 
  std::cout << insertBefore(t2) << std::endl; 
  std::cout << replace(t1) << std::endl; 
  std::cout << t2 << ", " << t1 << std::endl; 
    
  std::cout << "========= Text Manipulator: =========" << std::endl;
  TextManipulator tm;
  tm.insert(replace);
  tm.insert(appendTo);
  tm.insert(insertBefore);

  std::cout << tm.manipulate(t1) << std::endl;
  std::cout << t1 << std::endl;
  
  tm.clear();
  tm.insert(insertBefore);
  tm.insert(appendTo);
  std::cout << tm.manipulate(t1) << std::endl;  
}
/* oczekiwany wynik:
===== Test inkrementacji: =====
Number*
Number*Number*
Number*Number*Number*Number*
===== Test operacji na tekscie: =====
Jeden
Jeden dwa
zero Jeden dwa
trzy
Jeden dwa, Jeden
========= Text Manipulator: =========
zero trzy dwa
Jeden
zero Jeden dwa

*/
