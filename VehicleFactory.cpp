#include "VehicleFactory.h"

std::unique_ptr<Vehicle> VehicleFactory::createElectricCar(
    const std::string& make, const std::string& model, int year, 
    int doors, double batteryCapacity) {
    
    return std::make_unique<ElectricCar>(make, model, year, doors, batteryCapacity);
}

std::unique_ptr<Vehicle> VehicleFactory::createGasolineCar(
    const std::string& make, const std::string& model, int year, 
    int doors, double fuelCapacity) {
    
    return std::make_unique<GasolineCar>(make, model, year, doors, fuelCapacity);
}