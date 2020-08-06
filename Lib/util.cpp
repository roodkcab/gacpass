#include "util.hpp"

#include <stdlib.h>
#include <string>

const wchar_t* Appdata(const wchar_t *filename)
{
	wchar_t* appdata;
	size_t appdata_len;
	errno_t err = _wdupenv_s(&appdata, &appdata_len, L"APPDATA");
	std::wstring path(appdata);

	path.append(L"\\GacPass");
	path.append(filename);
	return path.c_str();
}