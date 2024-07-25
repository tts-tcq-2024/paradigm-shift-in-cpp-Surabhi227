#include "battery_check.h"
#include "language.h"
#include <iostream>

using namespace std;

bool CheckInRange(float value, float min, float max, const char* messageKey) {
  if (value < min || value > max) {
    cout << GetErrorMessage(messageKey) << endl;
    return false;
  }
  return true;
}

bool BatteryIsOk(float temperature, float soc, float chargeRate) {
  bool temperatureOk = CheckInRange(temperature, 0, 45, "Temperature out of range!");
  bool socOk = CheckInRange(soc, 20, 80, "State of Charge out of range!");
  bool chargeRateOk = CheckInRange(chargeRate, 0, 0.8, "Charge Rate out of range!");
  return temperatureOk && socOk && chargeRateOk;
}
