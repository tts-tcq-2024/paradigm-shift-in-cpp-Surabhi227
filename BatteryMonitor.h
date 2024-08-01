#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <string>
#include <map>
#include "Language.h" 

extern const float TEMP_MIN;
extern const float TEMP_MAX;
extern const float SOC_MIN;
extern const float SOC_MAX;
extern const float CHARGE_RATE_MIN;
extern const float CHARGE_RATE_MAX;
extern const float WARNING_TOLERANCE;

extern std::map<std::string, std::string> messages;
extern Language currentLanguage;

bool IsOutOfRange(float value, float min, float max);
void PrintMessage(const std::string& messageKey);
bool CheckWarnings(float value, float min, float max, float tolerance, 
                   const std::string& lowWarningMsg, const std::string& highWarningMsg);
bool BatteryIsOk(float temperature, float soc, float chargeRate);

#endif 
