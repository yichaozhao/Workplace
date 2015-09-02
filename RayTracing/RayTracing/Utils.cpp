#include "Utils.h"
#include <windows.h>

void OutputToDebugWindow(std::string& string)
{
	std::wstring wstring = std::wstring(string.begin(), string.end());
	OutputDebugStringW(wstring.c_str());
}