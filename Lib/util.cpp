#include "util.hpp"

std::string Appdata(vl::WString filename)
{
	auto path = WAppdata(filename);
	std::wstring wpath(path.Buffer());
	return std::string(wpath.begin(), wpath.end());
}

vl::WString WAppdata(vl::WString filename)
{
#if defined(__WINDOWS__)
    wchar_t* appdata;
	size_t appdata_len;
	errno_t err = _wdupenv_s(&appdata, &appdata_len, L"APPDATA");
	vl::WString path(appdata);
	path += L"\\GacPass";
#else
    vl::WString path(L"/tmp/gacpass");
#endif
	if (filename.Length() > 0)
	{
		path += filename;
	}
	return path;
	return L"/tmp/gacpass" + filename;

}