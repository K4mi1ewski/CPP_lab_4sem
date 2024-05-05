/* Celem zadania jest przećwiczenie dziedziczenia wielokrotnego zgodnego z zasadą D.R.Y., zastosowania  decltype, auto oraz prostych wyrażeń lambda.
Dana jest klasa zarządzająca flotą pojazdów oraz klasy poszczególnych pojazdów.
Strukturę klas pojazdów i ich pól należy wywnioskować z poniższego kodu i umieścić w odpowiednich plikach nagłówkowych (dołączony jest jeden plik nagłówkowy i jest on przeznaczony tylko i wyłącznie dla klasy VehicleManager).
Warunkiem otrzymania dwóch punktów za kod jest zastosowanie decltype do rozmiaru wektora, zastosowanie auto oraz funkcji lambda do wyszukiwania pojazdów. 
UWAGA!
Nie wolno korzystać z algorytmów STL!
*/

#include <iostream>
#include "vehicleManager.h"

int main() {
  Vehicle nieznany("Ufo","z Marsa",2024);
  nieznany.printInfo();
  VehicleManager manager;
  // std::vector<Vehicle*> vehicles;
  manager.push_back(new Car("Toyota", "Corolla", 2021, 4,5)); //marka, model, rok produkcji, pojemność silnika, liczba miejsc
  manager.push_back(new Motorcycle("Honda", "CRV", 2019, false)); //marka, model, rok produkcji, czy ma sidecar
  manager.push_back(new Bicycle("Trek", "FX 2", 2023, 21)); // marca, model, rok produkcji, liczba przekładek (biegów)
  
  std::cout << "=== Pojazdy we flocie ===\n";
  manager.printVehicles();
  manager.push_back(new Car("VolksWagen", "Touran", 2023, 5,7));

  std::cout << "\n=== Pojazdy silnikowe ===" << std::endl;
  for (auto vehicle : manager.Vehicles()) {
    if (dynamic_cast<MotorizedVehicle*>(vehicle) != nullptr) {
      std::cout << vehicle->getBrand() << " " << vehicle->getModel() << std::endl;
    }
  }
  manager.push_back(new Car("Toyota", "Aygo", 2023, 2,4));
  manager.push_back(new Car("Honda", "CRV", 2022, 5,5));
  
  // Wyszukiwanie pojazdów na podstawie marki
  std::cout << "\n=== Pojazdy marki Toyota ===\n";
  std::string searchBrand = "Toyota";
  manager.printVehiclesByBrand(searchBrand);

  // Wyszukiwanie pojazdów na podstawie roku produkcji  
  std::cout << "\n=== Pojazdy wyprodukowane w 2023 roku ===\n";
  int searchYear = 2023;
  manager.printVehiclesByYear(searchYear);
  std::cout << "=== Liczba miejsc w pojazdach czterokołowych floty: " << manager.countSeats() << std::endl;

  return 0;
}

/****** Output ******
Marka: Ufo, model: z Marsa, rok produkcji: 2024
=== Pojazdy we flocie ===
Samochod - Marka: Toyota, model: Corolla, rok produkcji: 2021
Liczba drzwi: 4, liczba miejsc: 5
Motocykl - Marka: Honda, model: CRV, rok produkcji: 2019
Ma wózek boczny (sidecar): nie
Rower - Marka: Trek, model: FX 2, rok produkcji: 2023
Liczba przekładek: 21

=== Pojazdy silnikowe ===
Toyota Corolla
Honda CRV
VolksWagen Touran

=== Pojazdy marki Toyota ===
Samochod - Marka: Toyota, model: Corolla, rok produkcji: 2021
Liczba drzwi: 4, liczba miejsc: 5
Samochod - Marka: Toyota, model: Aygo, rok produkcji: 2023
Liczba drzwi: 2, liczba miejsc: 4
Liczba pojazdów marki Toyota: 2

=== Pojazdy wyprodukowane w 2023 roku ===
Rower - Marka: Trek, model: FX 2, rok produkcji: 2023
Liczba przekładek: 21
Samochod - Marka: VolksWagen, model: Touran, rok produkcji: 2023
Liczba drzwi: 5, liczba miejsc: 7
Samochod - Marka: Toyota, model: Aygo, rok produkcji: 2023
Liczba drzwi: 2, liczba miejsc: 4
Liczba pojazdów z rocznika 2023: 3
=== Liczba miejsc w pojazdach czterokołowych floty: 21
*/
