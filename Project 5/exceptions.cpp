/* 
Exceptions separate the "happy path" (normal logic) from the error-handling logic.
*/

#include <iostream>
#include <stdexcept>

class HardwareFaultException : public std::runtime_error {
public:
    HardwareFaultException(const std::string& msg) : std::runtime_error(msg) {}
};

double readSensor(int id) {
    if (id < 0) {
        // We THROW an exception when an unrecoverable error occurs
        throw std::invalid_argument("Sensor ID cannot be negative.");
    }
    if (id == 99) {
        throw HardwareFaultException("Sensor 99 disconnected on I2C bus.");
    }
    return 3.14; // Fake reading
}

int main() {
    try {
        std::cout << "Reading sensor 1: " << readSensor(1) << '\n';
        std::cout << "Reading sensor 99: " << readSensor(99) << '\n'; // Will throw
    } catch (const HardwareFaultException& e) {
        std::cerr << "[HARDWARE FAULT] " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "[STANDARD ERROR] " << e.what() << '\n';
    }
    
    std::cout << "System continues running safely.\n";
    return 0;
}