#ifndef INTERFACES_H
#define INTERFACES_H

/**
 * @brief Interface for electric vehicles
 * Demonstrates Interface Segregation Principle
 */
class IElectric {
public:
    virtual ~IElectric() = default;
    virtual void chargeBattery() const = 0;
    virtual double getBatteryCapacity() const = 0;
};

/**
 * @brief Interface for fuel vehicles
 * Demonstrates Interface Segregation Principle
 */
class IFuel {
public:
    virtual ~IFuel() = default;
    virtual void refuel() const = 0;
    virtual double getFuelCapacity() const = 0;
};

#endif