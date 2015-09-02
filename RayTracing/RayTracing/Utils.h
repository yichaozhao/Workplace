#pragma once
#include <string>
#include <windows.h>

void OutputToDebugWindow(std::string& string);
#define DebugW(n) OutputDebugStringW(std::wstring(n).c_str());
