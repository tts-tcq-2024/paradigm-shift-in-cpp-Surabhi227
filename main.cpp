#include "battery_check.h"
#include "language.h"
#include <assert.h>
#include <iostream>

using namespace std;

int main() {
  InitializeErrorMessages();

  // Test in English
  currentLanguage = ENGLISH;
  assert(BatteryIsOk(25, 70, 0.7) == true);    // All parameters within range
  assert(BatteryIsOk(50, 70, 0.7) == false);   // Temperature out of range
  assert(BatteryIsOk(25, 85, 0.7) == false);   // State of Charge out of range
  assert(BatteryIsOk(25, 70, 1.0) == false);   // Charge Rate out of range
  assert(BatteryIsOk(50, 85, 1.0) == false);   // All parameters out of range

  // Test in German
  currentLanguage = GERMAN;
  assert(BatteryIsOk(25, 70, 0.7) == true);    // All parameters within range
  assert(BatteryIsOk(50, 70, 0.7) == false);   // Temperature out of range
  assert(BatteryIsOk(25, 85, 0.7) == false);   // State of Charge out of range
  assert(BatteryIsOk(25, 70, 1.0) == false);   // Charge Rate out of range
  assert(BatteryIsOk(50, 85, 1.0) == false);   // All parameters out of range

  return 0;
}
