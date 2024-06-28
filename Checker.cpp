#include <assert.h>
#include <iostream>
using namespace std;
 
bool CheckInRange(float value, float min, float max, const char* message) {
  if (value < min || value > max) {
    cout << message << endl;
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
 
int main() {
  assert(BatteryIsOk(25, 70, 0.7) == true);
  assert(BatteryIsOk(50, 85, 0) == false);
}
