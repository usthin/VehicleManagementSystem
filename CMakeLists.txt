cmake_minimum_required(VERSION 3.29)
project(VehicleManagementSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(VehicleManagementSystem main.cpp
        VehicleException.h
        Interfaces.h
        Vehicle.h
        Vehicle.cpp
        Car.h
        Car.cpp
        ElectricCar.h
        ElectricCar.cpp
        GasolineCar.h
        GasolineCar.cpp
        VehicleService.h
        VehicleService.cpp
        VehicleFactory.h
        VehicleFactory.cpp
        VehicleManager.h
        VehicleManager.cpp
        Menu.h
        Menu.cpp)
