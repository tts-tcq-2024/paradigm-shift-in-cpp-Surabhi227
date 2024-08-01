#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

// Function declarations
bool CheckInRange(float value, float min, float max, float tolerance,
                  const std::string& breachMsg, const std::string& lowWarningMsg,
                  const std::string& highWarningMsg);
bool BatteryIsOk(float temperature, float soc, float chargeRate);

#endif // BATTERYMONITOR_H
