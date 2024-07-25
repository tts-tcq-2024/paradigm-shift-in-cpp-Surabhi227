#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

enum Language { ENGLISH, GERMAN };

extern Language currentLanguage;

void InitializeErrorMessages();
const char* GetErrorMessage(const char* messageKey);

#endif 
