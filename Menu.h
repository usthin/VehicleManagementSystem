#ifndef MENU_H
#define MENU_H

#include "VehicleManager.h"
#include "VehicleFactory.h"
#include <iostream>

class Menu {
public:
    static void displayMainMenu();
    static void displayVehicleTypes();
    static void handleAddVehicle(VehicleManager& manager);
    static void handleViewVehicle(const VehicleManager& manager);
    static void handleUpdateVehicle(VehicleManager& manager);
    static void handleDeleteVehicle(VehicleManager& manager);
};

#endif