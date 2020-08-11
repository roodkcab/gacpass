#include "util.hpp"

#include <stdlib.h>
#include <string>

std::string Appdata(vl::WString filename)
{
	wchar_t* appdata;
	size_t appdata_len;
	errno_t err = _wdupenv_s(&appdata, &appdata_len, L"APPDATA");
	vl::WString path(appdata);

	path += L"\\GacPass";
	if (filename.Length() > 0)
	{
		path += filename;
	}
	std::wstring wpath(path.Buffer());
	return std::string(wpath.begin(), wpath.end());
}