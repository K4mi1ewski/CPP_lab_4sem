#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

using namespace std;

class Vehicle
{
    public:
    Vehicle (const string& mar, const string& mod, int r): marka(mar), model(mod), rok(r){}
    virtual void printInfo() const;
    string getBrand() const;
    string getModel() const;
    int getYear() const;
    protected:
    string marka;
    string model;
    int rok;
};
class Bicycle: public Vehicle
{
    public:
    Bicycle(const string& mar, const string& mod, int r, int p): Vehicle(mar,mod,r), przerzutki(p){}
    void printInfo() const override;
    private:
    int przerzutki;
};
class MotorizedVehicle: public Vehicle
{
    public:
    MotorizedVehicle(const string& mar, const string& mod, int r): Vehicle(mar,mod,r){}
    void printInfo() const override;
    

};
class Car: public MotorizedVehicle
{
    public:
    Car(const string& mar, const string& mod, int r, int p, int m): MotorizedVehicle(mar, mod, r),drzwi(p), miejsca(m){}
    void printInfo() const override;
    int getseats() const;
    private:
    int drzwi;
    int miejsca;
};
class Motorcycle: public MotorizedVehicle
{
    public:
    Motorcycle(const string& mar, const string& mod, int r, bool flag): MotorizedVehicle(mar, mod, r), sidecar(flag){}
    void printInfo() const override;
    private:
    bool sidecar;
};
#endif