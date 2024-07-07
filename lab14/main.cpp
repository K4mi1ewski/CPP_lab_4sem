/* 
Celem zadania jest powtórzenie przeładowania operatorów, w tym operatora [].
Zdefiniować klasę reprezentującą tablicę asocjacyjną gdzie typ klucza i typ wartosci są składowymi klasy (jako osobna klasa albo struktura).
W zależności od umiejętności można skorzystać z gotowych kontenerów albo samodzielnie je zdefiniować. Proszę pamiętać, że podczas wykonania zadania nie wolno korzystać z internetu, notatek, ani żadnych innych materiałów.
Funkcje składowe należy odczytać z kodu. Należy zdefiniować operatory przypisania i operatory dostępu do elementów. Proszę pamiętać o regule 5 z poprzedniego semestru. 

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. 
Zadanie proszę wysłać w postaci archiwum zip albo tgz, w którym mają znaleźć się:
dwa katalogi include i src (z zawartością) oraz pliki main.cpp i CMakeLists.txt 
bez żadnych katalogów nadrzędnych (zwłaszcza anonimowych typu lab1).
Można spakować z linii poleceń:
zip -r Gr_nazwisko.zip include src main.cpp CMakeLists.txt 
lub
tar czvf Gr_nazwisko.tgz include src main.cpp CMakeLists.txt 
albo utworzyć archiwum za pomocą menadżera plików, zaznaczając wszystkie potrzebne pliki.
NIE WYSYŁAMY katalogu build. 

*/

#include <iostream>
#include <string>

#include "assoc.h"

using std::cout;
using std::endl;

int main() {
 
  TAssoc m,m1,m2;  // kolejność klucz, wartość
  m.insert("AGD", 249.99 ).insert("Jedzenie", 24.5 ); 
  cout << m[1];
  cout << "* Wydatki *\n" << m;

  m["Kosmetyki"] = 9.99; // dodawanie wartości za pomocą klucza
  m["Rozrywka"] = 95.9;
  m["Rozrywka"] += 44.5;
  cout << "Czy tak mozna dodac element zerowy? " << m["szkola"] << endl;// proba wyciagniecia elementu z Assoc
  cout << "* Wydatki po modyfikacji *\n" << m;
  cout << "Suma: " << m.sum() << endl;
  m2=m=m;
  
  cout << "\n***** Tablica const *****" << endl;
  const TAssoc cm = m2;  
  cout << "* Kopia *\n" << cm;

  cout << "Wartosc pod fizyka? " << cm["fizyka"] << endl;
  cout << "Czy jest nauka? \t" << (cm.contains("nauka")?"Znaleziono":"Nie znaleziono") << endl;
  cout << "Czy jest szkola? \t" << (cm.contains("szkola")?"Znaleziono":"Nie znaleziono") << endl;

  cout << "\n***** Const referencje *****" << endl;
  const TAssoc& ref_m = m;  
  cout << "Referencja const dla Kosmetyki: " << ref_m["Kosmetyki"] << endl;
  m["Kosmetyki"]+=15;
  cout << "Kosmetyki po zmianie: " << ref_m["Kosmetyki"] << endl << endl;

  m1=std::move(m2);

  cout << "* Po przeniesieniu m1 *\n" << m1;
  cout << "* Po przeniesieniu m2 *\n" << m2;

  return 0;
}
  

/* oczekiwany wynik
--- klucz: Jedzenie wartosc: 24.5
* Wydatki *
--- klucz: AGD wartosc: 249.99
--- klucz: Jedzenie wartosc: 24.5
Czy tak mozna dodac element zerowy? 0
* Wydatki po modyfikacji *
--- klucz: AGD wartosc: 249.99
--- klucz: Jedzenie wartosc: 24.5
--- klucz: Kosmetyki wartosc: 9.99
--- klucz: Rozrywka wartosc: 140.4
--- klucz: szkola wartosc: 0
Suma: 424.88

***** Tablica const *****
* Kopia *
--- klucz: AGD wartosc: 249.99
--- klucz: Jedzenie wartosc: 24.5
--- klucz: Kosmetyki wartosc: 9.99
--- klucz: Rozrywka wartosc: 140.4
--- klucz: szkola wartosc: 0
Wartosc pod fizyka? 0
Czy jest nauka?         Nie znaleziono
Czy jest szkola?        Znaleziono

***** Const referencje *****
Referencja const dla Kosmetyki: 9.99
Kosmetyki po zmianie: 24.99

* Po przeniesieniu m1 *
--- klucz: AGD wartosc: 249.99
--- klucz: Jedzenie wartosc: 24.5
--- klucz: Kosmetyki wartosc: 9.99
--- klucz: Rozrywka wartosc: 140.4
--- klucz: szkola wartosc: 0
* Po przeniesieniu m2 *

 */
