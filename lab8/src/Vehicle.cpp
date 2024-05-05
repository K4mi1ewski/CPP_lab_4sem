#include "Vehicle.h"
#include <iostream>

void Vehicle::printInfo() const 
{
    cout << "Marka: " << marka << ", model: " << model << ", rok produkcji: " << rok << endl;
}
string Vehicle::getBrand() const
{
    return marka;
}

string Vehicle::getModel()const
{
    return model;
}

int Vehicle::getYear() const
{
    return rok;
}
void Bicycle::printInfo() const
{
    Vehicle::printInfo();
    cout << "Liczba przekladek: " << przerzutki << endl;

}
void Car::printInfo() const 
{
    MotorizedVehicle::printInfo();
    cout << "Liczba drzwi: "<<drzwi << " , liczba miejsc: " << miejsca << endl;
}

int Car::getseats()const
{
    return miejsca;
}
void Motorcycle::printInfo() const
{
    MotorizedVehicle::printInfo();
    cout << "Ma wozek boczny (sidecar): " << (sidecar ? "tak" : "nie") << endl;

}
void MotorizedVehicle::printInfo() const
{
    Vehicle::printInfo();
}