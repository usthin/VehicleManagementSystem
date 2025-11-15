#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <memory>
#include "VehicleException.h"

/**
 * @brief Abstract base class representing a vehicle
 * Demonstrates Abstraction and Encapsulation
 */
class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;
    int id;
    static int nextId;

public:
    Vehicle(const std::string& make, const std::string& model, int year);
    virtual ~Vehicle() = default;

    // Pure virtual functions - makes this class abstract
    virtual void start() const = 0;
    virtual void stop() const = 0;
    virtual double calculateMaintenanceCost() const = 0;
    virtual std::unique_ptr<Vehicle> clone() const = 0;

    // Common functionality
    virtual void displayInfo() const;

    // Getters and setters with encapsulation
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    int getId() const;
    
    void setMake(const std::string& newMake);
    void setModel(const std::string& newModel);
    void setYear(int newYear);
};

#endif