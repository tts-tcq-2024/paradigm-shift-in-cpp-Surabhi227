#include "BatteryMonitor.h"
#include "Language.h"
#include <iostream>
#include <string>

const float TEMP_MIN = 0;
const float TEMP_MAX = 45;
const float SOC_MIN = 20;
const float SOC_MAX = 80;
const float CHARGE_RATE_MIN = 0;
const float CHARGE_RATE_MAX = 0.8;
const float WARNING_TOLERANCE = 0.05;

bool IsOutOfRange(float value, float min, float max) {
    return value < min || value > max;
}

void PrintMessage(const std::string& messageKey) {
    if (messages.find(messageKey) != messages.end()) {
        std::cout << messages[messageKey] << std::endl;
    }
}

bool CheckParameter(float value, float min, float max, float tolerance, 
                    const std::string& breachMsg, const std::string& lowWarningMsg, 
                    const std::string& highWarningMsg) {
    if (IsOutOfRange(value, min, max)) {
        PrintMessage(breachMsg);
        return false;
    }
    if (value < min + tolerance) {
        PrintMessage(lowWarningMsg);
    }
    if (value > max - tolerance) {
        PrintMessage(highWarningMsg);
    }
    return true;
}

bool BatteryIsOk(float temperature, float soc, float chargeRate) {
    bool temperatureOk = CheckParameter(temperature, TEMP_MIN, TEMP_MAX, TEMP_MAX * WARNING_TOLERANCE, 
                                        "TEMP_BREACH", "TEMP_LOW_WARNING", "TEMP_HIGH_WARNING");
    bool socOk = CheckParameter(soc, SOC_MIN, SOC_MAX, SOC_MAX * WARNING_TOLERANCE, 
                                "SOC_BREACH", "SOC_LOW_WARNING", "SOC_HIGH_WARNING");
    bool chargeRateOk = CheckParameter(chargeRate, CHARGE_RATE_MIN, CHARGE_RATE_MAX, CHARGE_RATE_MAX * WARNING_TOLERANCE, 
                                       "CHARGE_RATE_BREACH", "CHARGE_RATE_WARNING", "CHARGE_RATE_WARNING");
    return temperatureOk && socOk && chargeRateOk;
}
