#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include "Vehicle.h"
#include "ElectricCar.h"
#include "GasolineCar.h"
#include <memory>

/**
 * @brief Factory for creating vehicles
 * Demonstrates Factory Pattern
 */
class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> createElectricCar(
        const std::string& make, const std::string& model, int year, 
        int doors, double batteryCapacity);
        
    static std::unique_ptr<Vehicle> createGasolineCar(
        const std::string& make, const std::string& model, int year, 
        int doors, double fuelCapacity);
};

#endif