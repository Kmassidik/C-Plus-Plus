/* 
Static Polymorphism: Function Overloading
Static polymorphism happens at compile time. 
The compiler looks at the arguments you pass and wires up the exact function call. 
There is zero runtime overhead. 
*/
#include <iostream>
#include <vector>

class SignalProcessor {
public:
    // Overload 1: Process a single raw integer reading
    void process(int raw_sensor_value) {
        std::cout << "Processing raw ADC integer: " << raw_sensor_value << '\n';
    }

    // Overload 2: Process a calibrated float voltage
    void process(double voltage) {
        std::cout << "Processing calibrated voltage: " << voltage << "V\n";
    }

    // Overload 3: Process a batch of readings
    void process(const std::vector<double>& batch) {
        std::cout << "Processing batch of " << batch.size() << " readings.\n";
    }
};

int main() {
    SignalProcessor sp;
    sp.process(1024);            // Calls Overload 1
    sp.process(3.3);             // Calls Overload 2
    sp.process({1.1, 2.2, 3.3}); // Calls Overload 3
    return 0;
}