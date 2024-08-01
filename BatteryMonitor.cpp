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
bool IsOutOfRange(float value, float min, float max) {
    return value < min || value > max;
}

void PrintMessage(const std::string& messageKey) {
    if (messages.find(messageKey) != messages.end()) {
        std::cout << messages[messageKey] << std::endl;
    }
}

bool CheckWarnings(float value, float min, float max, float tolerance, 
                   const std::string& lowWarningMsg, const std::string& highWarningMsg) {
    bool hasWarning = false;
    if (value < min + tolerance) {
        PrintMessage(lowWarningMsg);
        hasWarning = true;
    }
    if (value > max - tolerance) {
        PrintMessage(highWarningMsg);
        hasWarning = true;
    }
    return hasWarning;
}

bool BatteryIsOk(float temperature, float soc, float chargeRate) {
    bool temperatureOk = !IsOutOfRange(temperature, TEMP_MIN, TEMP_MAX) &&
                         !CheckWarnings(temperature, TEMP_MIN, TEMP_MAX, TEMP_MAX * WARNING_TOLERANCE, 
                                         "TEMP_LOW_WARNING", "TEMP_HIGH_WARNING");
    bool socOk = !IsOutOfRange(soc, SOC_MIN, SOC_MAX) &&
                 !CheckWarnings(soc, SOC_MIN, SOC_MAX, SOC_MAX * WARNING_TOLERANCE, 
                                "SOC_LOW_WARNING", "SOC_HIGH_WARNING");
    bool chargeRateOk = !IsOutOfRange(chargeRate, CHARGE_RATE_MIN, CHARGE_RATE_MAX) &&
                        !CheckWarnings(chargeRate, CHARGE_RATE_MIN, CHARGE_RATE_MAX, CHARGE_RATE_MAX * WARNING_TOLERANCE, 
                                       "CHARGE_RATE_WARNING", "CHARGE_RATE_WARNING");
    return temperatureOk && socOk && chargeRateOk;
}
