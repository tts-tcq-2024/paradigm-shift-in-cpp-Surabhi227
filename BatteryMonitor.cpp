#include "BatteryMonitor.h"
#include <iostream>

// Constants definitions
const float TEMP_MIN = 0;
const float TEMP_MAX = 45;
const float SOC_MIN = 20;
const float SOC_MAX = 80;
const float CHARGE_RATE_MIN = 0;
const float CHARGE_RATE_MAX = 0.8;
const float WARNING_TOLERANCE = 0.05;

// Message maps and current language
std::map<std::string, std::string> messages;
Language currentLanguage = ENGLISH;

// Helper functions
bool CheckBreach(float value, float min, float max, const std::string& breachMsg) {
    if (value < min || value > max) {
        std::cout << messages[breachMsg] << std::endl;
        return false;
    }
    return true;
}

bool CheckWarning(float value, float min, float max, float tolerance, 
                   const std::string& lowWarningMsg, const std::string& highWarningMsg) {
    if (value < min + tolerance) {
        std::cout << messages[lowWarningMsg] << std::endl;
    }
    if (value > max - tolerance) {
        std::cout << messages[highWarningMsg] << std::endl;
    }
    return true;
}

bool BatteryIsOk(float temperature, float soc, float chargeRate) {
    bool temperatureOk = CheckBreach(temperature, TEMP_MIN, TEMP_MAX, "TEMP_BREACH") &&
                         CheckWarning(temperature, TEMP_MIN, TEMP_MAX, TEMP_MAX * WARNING_TOLERANCE, 
                                      "TEMP_LOW_WARNING", "TEMP_HIGH_WARNING");
    bool socOk = CheckBreach(soc, SOC_MIN, SOC_MAX, "SOC_BREACH") &&
                 CheckWarning(soc, SOC_MIN, SOC_MAX, SOC_MAX * WARNING_TOLERANCE, 
                              "SOC_LOW_WARNING", "SOC_HIGH_WARNING");
    bool chargeRateOk = CheckBreach(chargeRate, CHARGE_RATE_MIN, CHARGE_RATE_MAX, "CHARGE_RATE_BREACH") &&
                        CheckWarning(chargeRate, CHARGE_RATE_MIN, CHARGE_RATE_MAX, CHARGE_RATE_MAX * WARNING_TOLERANCE, 
                                     "CHARGE_RATE_WARNING", "CHARGE_RATE_WARNING");
    return temperatureOk && socOk && chargeRateOk;
}
