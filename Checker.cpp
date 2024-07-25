#include <assert.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

enum Language { ENGLISH, GERMAN };

Language currentLanguage = ENGLISH;

map<string, map<Language, string>> errorMessages;

void InitializeErrorMessages() {
  errorMessages["Temperature out of range!"] = {
    {ENGLISH, "Temperature out of range!"},
    {GERMAN, "Temperatur außerhalb des zulässigen Bereichs!"}
  };
  errorMessages["State of Charge out of range!"] = {
    {ENGLISH, "State of Charge out of range!"},
    {GERMAN, "Ladezustand außerhalb des zulässigen Bereichs!"}
  };
  errorMessages["Charge Rate out of range!"] = {
    {ENGLISH, "Charge Rate out of range!"},
    {GERMAN, "Laderate außerhalb des zulässigen Bereichs!"}
  };
}


const char* GetErrorMessage(const char* messageKey) {
  return errorMessages[messageKey][currentLanguage].c_str();
}

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

int main() {
  InitializeErrorMessages();

 
  currentLanguage = ENGLISH;
  assert(BatteryIsOk(25, 70, 0.7) == true);
  assert(BatteryIsOk(50, 85, 0) == false);

  
  currentLanguage = GERMAN;
  assert(BatteryIsOk(25, 70, 0.7) == true);
  assert(BatteryIsOk(50, 85, 0) == false);

  
  return 0;
}
