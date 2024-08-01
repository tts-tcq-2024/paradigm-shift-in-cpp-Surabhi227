#include "BatteryMonitor.h"
#include "Language.h"
#include <cassert>
#include <iostream>

void RunTests() {
    // English tests
    currentLanguage = ENGLISH;
    // Valid cases
    assert(BatteryIsOk(25, 70, 0.7) == true);
    assert(BatteryIsOk(0, 20, 0) == true); 
    assert(BatteryIsOk(45, 80, 0.8) == true); 
    
    // Warnings
    assert(BatteryIsOk(4, 50, 0.5) == true); // Approaching low temperature warning
    assert(BatteryIsOk(41, 50, 0.5) == true); // Approaching high temperature warning
    assert(BatteryIsOk(25, 24, 0.5) == true); // Approaching low SoC warning
    assert(BatteryIsOk(25, 76, 0.5) == true); // Approaching high SoC warning
    assert(BatteryIsOk(25, 70, 0.76) == true); // Approaching high charge rate warning

    // Invalid cases
    assert(BatteryIsOk(50, 85, 0) == false); // Temperature breach
    assert(BatteryIsOk(15, 85, 0) == false); // SoC breach
    assert(BatteryIsOk(25, 85, 0.9) == false); // Charge rate breach

    // German tests
    currentLanguage = GERMAN;
    // Valid cases
    assert(BatteryIsOk(25, 70, 0.7) == true);
    assert(BatteryIsOk(0, 20, 0) == true); 
    assert(BatteryIsOk(45, 80, 0.8) == true); 
    
    // Warnings
    assert(BatteryIsOk(4, 50, 0.5) == true); // Approaching low temperature warning
    assert(BatteryIsOk(41, 50, 0.5) == true); // Approaching high temperature warning
    assert(BatteryIsOk(25, 24, 0.5) == true); // Approaching low SoC warning
    assert(BatteryIsOk(25, 76, 0.5) == true); // Approaching high SoC warning
    assert(BatteryIsOk(25, 70, 0.76) == true); // Approaching high charge rate warning

    // Invalid cases
    assert(BatteryIsOk(50, 85, 0) == false); // Temperature breach
    assert(BatteryIsOk(15, 85, 0) == false); // SoC breach
    assert(BatteryIsOk(25, 85, 0.9) == false); // Charge rate breach

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    RunTests();
    return 0;
}
