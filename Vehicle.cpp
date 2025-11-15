#include "Vehicle.h"
#include <iostream>

// Initialize static member
int Vehicle::nextId = 1;

Vehicle::Vehicle(const std::string& make, const std::string& model, int year)
    : make(make), model(model), year(year), id(nextId++) {}

void Vehicle::displayInfo() const {
    std::cout << "ID: " << id << ", Make: " << make << ", Model: " << model << ", Year: " << year << std::endl;
}

std::string Vehicle::getMake() const { return make; }
std::string Vehicle::getModel() const { return model; }
int Vehicle::getYear() const { return year; }
int Vehicle::getId() const { return id; }

void Vehicle::setMake(const std::string& newMake) { 
    if (!newMake.empty()) make = newMake; 
    else throw VehicleException("Make cannot be empty");
}

void Vehicle::setModel(const std::string& newModel) { 
    if (!newModel.empty()) model = newModel; 
    else throw VehicleException("Model cannot be empty");
}

void Vehicle::setYear(int newYear) { 
    if (newYear > 1885 && newYear <= 2024) year = newYear; 
    else throw VehicleException("Invalid year");
}