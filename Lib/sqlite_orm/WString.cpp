#include "sqlite_orm/WString.h"

std::unique_ptr<std::string> WStringToString(const WString &string) {
	auto s = std::wstring(string.Buffer());
    return std::make_unique<std::string>(s.begin(), s.end());
}

WString WStringFromString(const std::string &s) {
	return WString(std::wstring(s.begin(), s.end()).c_str());
}

