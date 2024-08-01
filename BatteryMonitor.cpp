#include "BatteryMonitor.h"

// Define boundaries and messages
const float TEMP_MIN = 0;
const float TEMP_MAX = 45;
const float SOC_MIN = 20;
const float SOC_MAX = 80;
const float CHARGE_RATE_MIN = 0;
const float CHARGE_RATE_MAX = 0.8;

const float WARNING_TOLERANCE = 0.05;

// Define message mappings
std::map<Language, std::map<std::string, std::string>> messages = {
    {ENGLISH, {
        {"TEMP_LOW_WARNING", "Warning: Approaching low temperature"},
        {"TEMP_HIGH_WARNING", "Warning: Approaching high temperature"},
        {"TEMP_BREACH", "Temperature out of range!"},
        {"SOC_LOW_WARNING", "Warning: Approaching discharge"},
        {"SOC_HIGH_WARNING", "Warning: Approaching charge-peak"},
        {"SOC_BREACH", "State of Charge out of range!"},
        {"CHARGE_RATE_WARNING", "Warning: Approaching high charge rate"},
        {"CHARGE_RATE_BREACH", "Charge Rate out of range!"}
    }},
    {GERMAN, {
        {"TEMP_LOW_WARNING", "Warnung: Näher an niedriger Temperatur"},
        {"TEMP_HIGH_WARNING", "Warnung: Näher an hoher Temperatur"},
        {"TEMP_BREACH", "Temperatur außerhalb des Bereichs!"},
        {"SOC_LOW_WARNING", "Warnung: Näher an Entladung"},
        {"SOC_HIGH_WARNING", "Warnung: Näher an Ladepeak"},
        {"SOC_BREACH", "Ladezustand außerhalb des Bereichs!"},
        {"CHARGE_RATE_WARNING", "Warnung: Näher an hoher Ladegeschwindigkeit"},
        {"CHARGE_RATE_BREACH", "Ladegeschwindigkeit außerhalb des Bereichs!"}
    }}
};

Language currentLanguage = ENGLISH;

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
