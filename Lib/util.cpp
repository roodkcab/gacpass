#include "util.hpp"

std::string Appdata(vl::WString filename)
{
	auto path = WAppdata(filename);
	std::wstring wpath(path.Buffer());
	return std::string(wpath.begin(), wpath.end());
}

vl::WString WAppdata(vl::WString filename)
{
	wchar_t* appdata = nullptr;
	size_t appdata_len;
	errno_t err = _wdupenv_s(&appdata, &appdata_len, L"APPDATA");
	if (_wdupenv_s(&appdata, &appdata_len, L"APPDATA") == 0 && appdata != nullptr)
	{
		vl::WString path(appdata);
		free(appdata);
		path += L"\\GacPass";
		if (filename.Length() > 0)
		{
			path += filename;
		}
		return path;
	}
	return L"";
}