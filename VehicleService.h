#ifndef VEHICLE_SERVICE_H
#define VEHICLE_SERVICE_H

#include "Vehicle.h"

/**
 * @brief Service interface for vehicle maintenance
 * Demonstrates Dependency Inversion Principle
 */
class IVehicleService {
public:
    virtual ~IVehicleService() = default;
    virtual void performService(const Vehicle& vehicle) const = 0;
    virtual double calculateServiceCost(const Vehicle& vehicle) const = 0;
};

/**
 * @brief Concrete service implementation
 */
class BasicService : public IVehicleService {
public:
    void performService(const Vehicle& vehicle) const override;
    double calculateServiceCost(const Vehicle& vehicle) const override;
};

#endif