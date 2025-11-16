#include "VehicleManager.h"
#include <iostream>
#include <algorithm>

VehicleManager::VehicleManager(std::unique_ptr<IVehicleService> service) 
    : service(std::move(service)) {}

typename std::vector<std::unique_ptr<Vehicle>>::iterator VehicleManager::findVehicleById(int id) {
    return std::find_if(vehicles.begin(), vehicles.end(),
        [id](const std::unique_ptr<Vehicle>& vehicle) {
            return vehicle->getId() == id;
        });
}

void VehicleManager::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    if (!vehicle) {
        throw VehicleException("Cannot add null vehicle");
    }
    vehicles.push_back(std::move(vehicle));
    std::cout << "Vehicle added successfully. ID: " << vehicles.back()->getId() << std::endl;
}

void VehicleManager::displayAllVehicles() const {
    if (vehicles.empty()) {
        std::cout << "No vehicles in the system." << std::endl;
        return;
    }

    std::cout << "\n=== VEHICLE FLEET (" << vehicles.size() << " vehicles) ===" << std::endl;
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
        std::cout << "---------------------" << std::endl;
    }
}

const Vehicle* VehicleManager::getVehicleById(int id) const {
    auto it = std::find_if(vehicles.begin(), vehicles.end(),
        [id](const std::unique_ptr<Vehicle>& vehicle) {
            return vehicle->getId() == id;
        });
    
    if (it != vehicles.end()) {
        return it->get();
    }
    return nullptr;
}

void VehicleManager::updateVehicle(int id, const std::string& make, const std::string& model, int year) {
    auto it = findVehicleById(id);
    if (it != vehicles.end()) {
        (*it)->setMake(make);
        (*it)->setModel(model);
        (*it)->setYear(year);
        std::cout << "Vehicle with ID " << id << " updated successfully." << std::endl;
    } else {
        throw VehicleException("Vehicle with ID " + std::to_string(id) + " not found");
    }
}

void VehicleManager::removeVehicle(int id) {
    auto it = findVehicleById(id);
    if (it != vehicles.end()) {
        std::cout << "Removing vehicle: ";
        (*it)->displayInfo();
        vehicles.erase(it);
        std::cout << "Vehicle with ID " << id << " removed successfully." << std::endl;
    } else {
        throw VehicleException("Vehicle with ID " + std::to_string(id) + " not found");
    }
}

void VehicleManager::serviceAllVehicles() const {
    if (vehicles.empty()) {
        std::cout << "No vehicles to service." << std::endl;
        return;
    }

    std::cout << "\n=== SERVICING ALL VEHICLES ===" << std::endl;
    for (const auto& vehicle : vehicles) {
        service->performService(*vehicle);
        std::cout << "---------------------" << std::endl;
    }
}

void VehicleManager::startAllVehicles() const {
    if (vehicles.empty()) {
        std::cout << "No vehicles to start." << std::endl;
        return;
    }

    std::cout << "\n=== STARTING ALL VEHICLES ===" << std::endl;
    for (const auto& vehicle : vehicles) {
        vehicle->start();
    }
}

size_t VehicleManager::getVehicleCount() const {
    return vehicles.size();
}