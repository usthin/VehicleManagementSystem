#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

#include "Car.h"
#include "Interfaces.h"

/**
 * @brief Electric car implementing both Vehicle and IElectric interfaces
 * Demonstrates Multiple Inheritance
 */
class ElectricCar : public Car, public IElectric {
private:
    double batteryCapacity;
    double currentCharge;

public:
    ElectricCar(const std::string& make, const std::string& model, int year, 
                int doors, double batteryCapacity, double initialCharge = 80.0);
    
    // Override Vehicle methods
    void start() const override;
    double calculateMaintenanceCost() const override;
    void displayInfo() const override;
    std::unique_ptr<Vehicle> clone() const override;

    // Implement IElectric interface
    void chargeBattery() const override;
    double getBatteryCapacity() const override;

    // ElectricCar specific methods
    double getCurrentCharge() const;
    void setCurrentCharge(double charge);
};

#endif