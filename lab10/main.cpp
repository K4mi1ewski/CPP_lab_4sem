/*
Tematem zadania jest implementacja klasy, który przeszuka tekst wczytany z pliku tekstowego w poszukiwaniu określonego słowa za pomocą wielowątkowości i algorytmów, np. std::find albo std::search. Można korzystać z dokumentacji 
https://cplusplus.com/reference/algorithm/ w celu zastosowania innych algorytmów jak np accomodate.

Utwórz klasę TextSearcher, która będzie odpowiedzialna za wielowątkowe przeszukiwanie tekstu. Klasa posiada następujące metody:
- loadTextFromFile - metoda do wczytania tekstu z pliku tekstowego, który ma być przeszukiwany.
- multiThreadedSearch - metoda do przeszukiwania tekstu w poszukiwaniu określonego słowa przez liczbę zadanych w argumencie wątków. Zwraca obiekt przechowujący liczbę znalezionych słów w kolejnych wątkach.
- countResults - zwraca liczbę wszystkich wystąpień określonego słowa w tekście.
- printResults - drukuje wyniki przeszukiwania.

Wewnątrz metody wyszukujacej użyj std::async do uruchomienia wielu wątków, które przeszukają tekst w poszukiwaniu słowa. Każdy wątek będzie przeszukiwał część tekstu.
Podziel tekst na fragmenty i przypisz każdy fragment do innego wątku. Można zignorować sytuację, w którym wyszukiwane słowo znajdzie się na granicy podziału. Wykorzystaj mechanizm std::future do monitorowania zakończenia pracy wątków.
*/

#include <iostream>
#include "textSearcher.h"

int main() {
    TextSearcher searcher;
    std::string filename = "../Pan_Tadeusz.txt";
    std::string word = "Tadeusz";
    searcher.loadTextFromFile("Pan_Tadeusz.txt");
     auto threadCount = std::thread::hardware_concurrency();
     auto threadResults = searcher.multiThreadedSearch("Pan", threadCount);

      threadCount = 8; // odkomentować gdyby sprzętowo była inna liczba wątków
     searcher.loadTextFromFile(filename);
     std::cout << "Wyszukiwanie słowa '" << word << "' przy użyciu " << threadCount << " wątków:" << std::endl;

     threadResults = searcher.multiThreadedSearch(word, threadCount);
     std::cout << "Liczba wszystkich wystapien: " << searcher.countResults(threadResults) << std::endl;
     searcher.printResults(threadResults);
    //    std::cout << searcher.getText() << endl;
     threadCount = 16; // zwiększamy liczbę wątków
     word = "tak";
     std::cout << "Wyszukiwanie słowa '" << word << "' przy użyciu " << threadCount << " wątków:" << std::endl;

     threadResults = searcher.multiThreadedSearch(word, threadCount);
     std::cout << "Liczba wszystkich wystapien: " << searcher.countResults(threadResults) << std::endl;
     searcher.printResults(threadResults);

    return 0;
}

/* Oczekiwany wynik:
[ERROR] Nie można otworzyć pliku: Pan_Tadeusz.txt
[ERROR] Bufor jest pusty
Wyszukiwanie słowa 'Tadeusz' przy użyciu 8 wątków:
Liczba wszystkich wystapien: 184
Wątek 1: 35
Wątek 2: 27
Wątek 3: 23
Wątek 4: 29
Wątek 5: 18
Wątek 6: 26
Wątek 7: 12
Wątek 8: 14
Wyszukiwanie słowa 'tak' przy użyciu 16 wątków:
Liczba wszystkich wystapien: 365
Wątek 1: 20
Wątek 2: 22
Wątek 3: 23
Wątek 4: 18
Wątek 5: 20
Wątek 6: 13
Wątek 7: 21
Wątek 8: 12
Wątek 9: 26
Wątek 10: 23
Wątek 11: 34
Wątek 12: 20
Wątek 13: 30
Wątek 14: 26
Wątek 15: 25
Wątek 16: 32
*/