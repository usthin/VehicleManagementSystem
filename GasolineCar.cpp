#include "GasolineCar.h"
#include <iostream>

GasolineCar::GasolineCar(const std::string& make, const std::string& model, int year, 
                         int doors, double fuelCapacity, double initialFuel)
    : Car(make, model, year, doors, 0), fuelCapacity(fuelCapacity), currentFuel(initialFuel) {}

void GasolineCar::start() const {
    if (currentFuel > 1) {
        std::cout << "Gasoline car " << make << " " << model << " is starting with engine sound..." << std::endl;
    } else {
        std::cout << "Not enough fuel to start!" << std::endl;
    }
}

void GasolineCar::displayInfo() const {
    Car::displayInfo();
    std::cout << "Fuel: " << currentFuel << "/" << fuelCapacity << " liters" << std::endl;
}

std::unique_ptr<Vehicle> GasolineCar::clone() const {
    return std::make_unique<GasolineCar>(*this);
}

void GasolineCar::refuel() const {
    std::cout << "Refueling " << make << " " << model << " with gasoline..." << std::endl;
}

double GasolineCar::getFuelCapacity() const {
    return fuelCapacity;
}

double GasolineCar::getCurrentFuel() const { 
    return currentFuel; 
}

void GasolineCar::setCurrentFuel(double fuel) { 
    if (fuel >= 0 && fuel <= fuelCapacity) currentFuel = fuel; 
    else throw VehicleException("Fuel level must be between 0 and capacity");
}