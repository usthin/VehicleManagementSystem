#ifndef GASOLINE_CAR_H
#define GASOLINE_CAR_H

#include "Car.h"
#include "Interfaces.h"

/**
 * @brief Gasoline car implementing both Vehicle and IFuel interfaces
 */
class GasolineCar : public Car, public IFuel {
private:
    double fuelCapacity;
    double currentFuel;

public:
    GasolineCar(const std::string& make, const std::string& model, int year, 
                int doors, double fuelCapacity, double initialFuel = 0);
    
    // Override Vehicle methods
    void start() const override;
    void displayInfo() const override;
    std::unique_ptr<Vehicle> clone() const override;

    // Implement IFuel interface
    void refuel() const override;
    double getFuelCapacity() const override;

    // GasolineCar specific methods
    double getCurrentFuel() const;
    void setCurrentFuel(double fuel);
};

#endif