#include "VehicleService.h"
#include <iostream>

void BasicService::performService(const Vehicle& vehicle) const {
    std::cout << "Performing basic service on " << vehicle.getMake() << " " << vehicle.getModel() << std::endl;
    std::cout << "Service cost: $" << calculateServiceCost(vehicle) << std::endl;
}

double BasicService::calculateServiceCost(const Vehicle& vehicle) const {
    return vehicle.calculateMaintenanceCost() * 0.8; // 20% discount for basic service
}