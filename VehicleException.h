#ifndef VEHICLE_EXCEPTION_H
#define VEHICLE_EXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * @brief Custom exception for vehicle-related errors
 */
class VehicleException : public std::runtime_error {
public:
    explicit VehicleException(const std::string& message) 
        : std::runtime_error(message) {}
};

#endif