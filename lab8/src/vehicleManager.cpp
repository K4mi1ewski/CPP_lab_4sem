#include "vehicleManager.h"

void VehicleManager::printVehicles() const
{
    for (auto el: vehicles)
    {
        el->printInfo();
    }
}
vector<Vehicle*> VehicleManager::Vehicles() const
{
    return vehicles;
}
void VehicleManager::push_back(Vehicle* ptr)
{
    vehicles.push_back(ptr);
}
int VehicleManager::countSeats() const
{
    int sum = 0;
    for (auto el: vehicles)
    {
        if (dynamic_cast<Car*>(el) != nullptr)
        {
            auto ptr = dynamic_cast<Car*>(el);
            sum+=ptr->getseats();
        }
    }
    return sum;
}
