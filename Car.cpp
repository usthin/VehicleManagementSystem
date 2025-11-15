#include "Car.h"
#include <iostream>

Car::Car(const std::string& make, const std::string& model, int year, int doors, double mileage)
    : Vehicle(make, model, year), doors(doors), mileage(mileage) {}

void Car::start() const {
    std::cout << "Car " << make << " " << model << " is starting..." << std::endl;
}

void Car::stop() const {
    std::cout << "Car " << make << " " << model << " is stopping..." << std::endl;
}

double Car::calculateMaintenanceCost() const {
    return 100.0 + (mileage * 0.05);
}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Doors: " << doors << ", Mileage: " << mileage << " miles" << std::endl;
}

std::unique_ptr<Vehicle> Car::clone() const {
    return std::make_unique<Car>(*this);
}

int Car::getDoors() const { return doors; }
double Car::getMileage() const { return mileage; }

void Car::setDoors(int newDoors) { 
    if (newDoors > 0 && newDoors <= 6) doors = newDoors; 
    else throw VehicleException("Invalid number of doors");
}

void Car::setMileage(double newMileage) { 
    if (newMileage >= 0) mileage = newMileage; 
    else throw VehicleException("Mileage cannot be negative");
}