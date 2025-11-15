#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

/**
 * @brief Concrete class representing a car
 * Demonstrates Inheritance from Vehicle
 */
class Car : public Vehicle {
protected:
    int doors;
    double mileage;

public:
    Car(const std::string& make, const std::string& model, int year, int doors, double mileage = 0);
    
    // Override Vehicle methods
    void start() const override;
    void stop() const override;
    double calculateMaintenanceCost() const override;
    void displayInfo() const override;
    std::unique_ptr<Vehicle> clone() const override;

    // Car-specific methods
    int getDoors() const;
    double getMileage() const;
    void setDoors(int newDoors);
    void setMileage(double newMileage);
};

#endif