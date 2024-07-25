#include "language.h"
#include <map>
#include <string>

using namespace std;

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
