#include "Menu.h"

void Menu::displayMainMenu() {
    std::cout << "\n=== VEHICLE MANAGEMENT SYSTEM ===" << std::endl;
    std::cout << "1. Add a new vehicle" << std::endl;
    std::cout << "2. View all vehicles" << std::endl;
    std::cout << "3. View a specific vehicle" << std::endl;
    std::cout << "4. Update a vehicle" << std::endl;
    std::cout << "5. Delete a vehicle" << std::endl;
    std::cout << "6. Service all vehicles" << std::endl;
    std::cout << "7. Start all vehicles" << std::endl;
    std::cout << "8. Display statistics" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Please enter your choice: ";
}

void Menu::displayVehicleTypes() {
    std::cout << "\nSelect vehicle type:" << std::endl;
    std::cout << "1. Electric Car" << std::endl;
    std::cout << "2. Gasoline Car" << std::endl;
    std::cout << "Enter your choice: ";
}

void Menu::handleAddVehicle(VehicleManager& manager) {
    displayVehicleTypes();
    int typeChoice;
    std::cin >> typeChoice;
    std::cin.ignore();

    std::string make, model;
    int year, doors;

    std::cout << "Enter make: ";
    std::getline(std::cin, make);
    std::cout << "Enter model: ";
    std::getline(std::cin, model);
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter number of doors: ";
    std::cin >> doors;

    if (typeChoice == 1) {
        double batteryCapacity;
        std::cout << "Enter battery capacity (kWh): ";
        std::cin >> batteryCapacity;
        manager.addVehicle(VehicleFactory::createElectricCar(make, model, year, doors, batteryCapacity));
    } else if (typeChoice == 2) {
        double fuelCapacity;
        std::cout << "Enter fuel capacity (liters): ";
        std::cin >> fuelCapacity;
        manager.addVehicle(VehicleFactory::createGasolineCar(make, model, year, doors, fuelCapacity));
    } else {
        std::cout << "Invalid vehicle type selection." << std::endl;
    }
}

void Menu::handleViewVehicle(const VehicleManager& manager) {
    int id;
    std::cout << "Enter vehicle ID: ";
    std::cin >> id;
    
    const Vehicle* vehicle = manager.getVehicleById(id);
    if (vehicle) {
        std::cout << "\n=== VEHICLE DETAILS ===" << std::endl;
        vehicle->displayInfo();
    } else {
        std::cout << "Vehicle with ID " << id << " not found." << std::endl;
    }
}

void Menu::handleUpdateVehicle(VehicleManager& manager) {
    int id;
    std::string make, model;
    int year;
    
    std::cout << "Enter vehicle ID to update: ";
    std::cin >> id;
    std::cin.ignore();
    
    std::cout << "Enter new make: ";
    std::getline(std::cin, make);
    std::cout << "Enter new model: ";
    std::getline(std::cin, model);
    std::cout << "Enter new year: ";
    std::cin >> year;
    
    manager.updateVehicle(id, make, model, year);
}

void Menu::handleDeleteVehicle(VehicleManager& manager) {
    int id;
    std::cout << "Enter vehicle ID to delete: ";
    std::cin >> id;
    
    manager.removeVehicle(id);
}