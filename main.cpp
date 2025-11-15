#include <iostream>
#include <memory>
#include "VehicleManager.h"
#include "VehicleService.h"
#include "Menu.h"
#include "VehicleException.h"

int main() {
    std::cout << "=== OOP VEHICLE MANAGEMENT SYSTEM WITH CRUD ===" << std::endl;

    try {
        // Create service using dependency injection
        auto service = std::make_unique<BasicService>();
        VehicleManager manager(std::move(service));

        int choice;
        bool running = true;

        while (running) {
            try {
                Menu::displayMainMenu();
                std::cin >> choice;
                std::cin.ignore(); // Clear the input buffer

                switch (choice) {
                    case 1:
                        Menu::handleAddVehicle(manager);
                        break;
                    case 2:
                        manager.displayAllVehicles();
                        break;
                    case 3:
                        Menu::handleViewVehicle(manager);
                        break;
                    case 4:
                        Menu::handleUpdateVehicle(manager);
                        break;
                    case 5:
                        Menu::handleDeleteVehicle(manager);
                        break;
                    case 6:
                        manager.serviceAllVehicles();
                        break;
                    case 7:
                        manager.startAllVehicles();
                        break;
                    case 8:
                        std::cout << "Total vehicles in system: " << manager.getVehicleCount() << std::endl;
                        break;
                    case 9:
                        running = false;
                        std::cout << "Exiting system. Goodbye!" << std::endl;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } catch (const VehicleException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Unexpected error: " << e.what() << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize system: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}