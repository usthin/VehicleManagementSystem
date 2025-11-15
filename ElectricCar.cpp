#include "ElectricCar.h"
#include <iostream>

ElectricCar::ElectricCar(const std::string& make, const std::string& model, int year, 
                         int doors, double batteryCapacity, double initialCharge)
    : Car(make, model, year, doors, 0), batteryCapacity(batteryCapacity), currentCharge(initialCharge) {}

void ElectricCar::start() const {
    if (currentCharge > 10) {
        std::cout << "Electric car " << make << " " << model << " is starting silently..." << std::endl;
    } else {
        std::cout << "Battery too low to start!" << std::endl;
    }
}

double ElectricCar::calculateMaintenanceCost() const {
    return 50.0 + (mileage * 0.02);
}

void ElectricCar::displayInfo() const {
    Car::displayInfo();
    std::cout << "Battery: " << batteryCapacity << " kWh, Charge: " << currentCharge << "%" << std::endl;
}

std::unique_ptr<Vehicle> ElectricCar::clone() const {
    return std::make_unique<ElectricCar>(*this);
}

void ElectricCar::chargeBattery() const {
    std::cout << "Charging " << make << " " << model << " battery..." << std::endl;
}

double ElectricCar::getBatteryCapacity() const {
    return batteryCapacity;
}

double ElectricCar::getCurrentCharge() const { 
    return currentCharge; 
}

void ElectricCar::setCurrentCharge(double charge) { 
    if (charge >= 0 && charge <= 100) currentCharge = charge; 
    else throw VehicleException("Charge must be between 0 and 100");
}