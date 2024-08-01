#ifndef LANGUAGE_H
#define LANGUAGE_H

include <map>
#include <string>
#include "BatteryMonitor.h"

// Global variable for language setting
enum Language { ENGLISH, GERMAN };
extern Language currentLanguage = ENGLISH;

// Define message mappings
extern std::map<Language, std::map<std::string, std::string>> messages;

#endif 
