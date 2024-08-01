#include "language.h"


std::map<Language, std::map<std::string, std::string>> messages = {
    {ENGLISH, {
        {"TEMP_LOW_WARNING", "Warning: Approaching low temperature"},
        {"TEMP_HIGH_WARNING", "Warning: Approaching high temperature"},
        {"TEMP_BREACH", "Temperature out of range!"},
        {"SOC_LOW_WARNING", "Warning: Approaching discharge"},
        {"SOC_HIGH_WARNING", "Warning: Approaching charge-peak"},
        {"SOC_BREACH", "State of Charge out of range!"},
        {"CHARGE_RATE_WARNING", "Warning: Approaching high charge rate"},
        {"CHARGE_RATE_BREACH", "Charge Rate out of range!"}
    }},
    {GERMAN, {
        {"TEMP_LOW_WARNING", "Warnung: Näher an niedriger Temperatur"},
        {"TEMP_HIGH_WARNING", "Warnung: Näher an hoher Temperatur"},
        {"TEMP_BREACH", "Temperatur außerhalb des Bereichs!"},
        {"SOC_LOW_WARNING", "Warnung: Näher an Entladung"},
        {"SOC_HIGH_WARNING", "Warnung: Näher an Ladepeak"},
        {"SOC_BREACH", "Ladezustand außerhalb des Bereichs!"},
        {"CHARGE_RATE_WARNING", "Warnung: Näher an hoher Ladegeschwindigkeit"},
        {"CHARGE_RATE_BREACH", "Ladegeschwindigkeit außerhalb des Bereichs!"}
    }}
};
