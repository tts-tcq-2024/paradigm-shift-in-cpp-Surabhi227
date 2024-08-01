#include "Language.h"
#include <string>
#include <map>

std::map<std::string, std::string> messages = {
    { "TEMP_LOW_WARNING", "Warning: Approaching low temperature" },
    { "TEMP_HIGH_WARNING", "Warning: Approaching high temperature" },
    { "TEMP_BREACH", "Temperature out of range!" },
    { "SOC_LOW_WARNING", "Warning: Approaching discharge" },
    { "SOC_HIGH_WARNING", "Warning: Approaching charge-peak" },
    { "SOC_BREACH", "State of Charge out of range!" },
    { "CHARGE_RATE_WARNING", "Warning: Approaching high charge rate" },
    { "CHARGE_RATE_BREACH", "Charge Rate out of range!" }
};

Language currentLanguage = ENGLISH;
