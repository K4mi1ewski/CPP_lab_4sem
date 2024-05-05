#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H
#include "Vehicle.h"
#include <vector>
#include <functional>
#include <iostream>
class VehicleManager
{
    public:
    void printVehicles() const;
    vector<Vehicle*> Vehicles() const;
    void push_back(Vehicle* ptr);
    int countSeats() const;

    
    private:
    vector<Vehicle*> vehicles;

    public:
    //void printVehiclesByBrand(const string& str) {}
    //void printVehiclesByYear(const int n) {}
    function<void(const string& str)> printVehiclesByBrand = [&](const string& brand){
        int counter = 0;
        for (auto el: vehicles)
        {

            if (el->getBrand()==brand)
            {el->printInfo(); counter++;}
        }
        cout << "Liczba pojazdow marki " << brand << ": " << counter << endl;
        };

    function<void(const int y)> printVehiclesByYear = [&](const int year)
    {
        int counter = 0;
        for (auto el: vehicles)
        {
            if (el->getYear()==year)
            {el->printInfo(); counter++;}
        }
        cout << "Liczba pojazdow z rocznika " << year << ": " << counter << endl;
    };
};
#endif