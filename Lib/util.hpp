#ifndef UTIL_H_
#define UTIL_H_

#include "Vlpp.h"
#include <string>

std::string Appdata(vl::WString filename);
vl::WString WAppdata(vl::WString filename);

std::wstring String2WString(const std::string& input);
std::string WString2String(const std::wstring& input);

#endif
