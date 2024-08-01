#include "BatteryMonitor.h"
#include "language.h"
#include <iostream>

bool CheckInRange(float value, float min, float max, float tolerance,
                  const std::string& breachMsg, const std::string& lowWarningMsg,
                  const std::string& highWarningMsg) {
    if (value < min || value > max) {
        std::cout << messages[currentLanguage][breachMsg] << std::endl;
        return false;
    }
    if (value < min + tolerance) {
        std::cout << messages[currentLanguage][lowWarningMsg] << std::endl;
    }
    if (value > max - tolerance) {
        std::cout << messages[currentLanguage][highWarningMsg] << std::endl;
    }
    return true;
}

bool BatteryIsOk(float temperature, float soc, float chargeRate) {
    bool temperatureOk = CheckInRange(temperature, TEMP_MIN, TEMP_MAX, TEMP_MAX * WARNING_TOLERANCE, 
                                      "TEMP_BREACH", "TEMP_LOW_WARNING", "TEMP_HIGH_WARNING");
    bool socOk = CheckInRange(soc, SOC_MIN, SOC_MAX, SOC_MAX * WARNING_TOLERANCE, 
                              "SOC_BREACH", "SOC_LOW_WARNING", "SOC_HIGH_WARNING");
    bool chargeRateOk = CheckInRange(chargeRate, CHARGE_RATE_MIN, CHARGE_RATE_MAX, CHARGE_RATE_MAX * WARNING_TOLERANCE, 
                                     "CHARGE_RATE_BREACH", "CHARGE_RATE_WARNING", "CHARGE_RATE_WARNING");
    return temperatureOk && socOk && chargeRateOk;
}
