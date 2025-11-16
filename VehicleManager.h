#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H

#include "Vehicle.h"
#include "VehicleService.h"
#include <vector>
#include <memory>

/**
 * @brief Manages a collection of vehicles with CRUD operations
 */
class VehicleManager {
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    std::unique_ptr<IVehicleService> service;

    // Helper method to find a vehicle by ID
    typename std::vector<std::unique_ptr<Vehicle>>::iterator findVehicleById(int id);

public:
    VehicleManager(std::unique_ptr<IVehicleService> service);
    
    // CRUD Operations
    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    void displayAllVehicles() const;
    const Vehicle* getVehicleById(int id) const;
    void updateVehicle(int id, const std::string& make, const std::string& model, int year);
    void removeVehicle(int id);
    
    // Additional operations
    void serviceAllVehicles() const;
    void startAllVehicles() const;
    size_t getVehicleCount() const;
};

#endif