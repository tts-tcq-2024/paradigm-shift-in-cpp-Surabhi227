#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <iostream>
#include <map>
#include <string>

// Global variable for language setting
enum Language { ENGLISH, GERMAN };
extern Language currentLanguage = ENGLISH;

// Function declarations
bool CheckInRange(float value, float min, float max, float tolerance,
                  const std::string& breachMsg, const std::string& lowWarningMsg,
                  const std::string& highWarningMsg);
bool BatteryIsOk(float temperature, float soc, float chargeRate);

const float TEMP_MIN = 0;
const float TEMP_MAX = 45;
const float SOC_MIN = 20;
const float SOC_MAX = 80;
const float CHARGE_RATE_MIN = 0;
const float CHARGE_RATE_MAX = 0.8;

const float WARNING_TOLERANCE = 0.05;

#endif // BATTERYMONITOR_H

