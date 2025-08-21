#pragma once

#include<string>
#include<vector>

#include"../w_lean.h"

struct LaunchResult
{
    DWORD error = 0;
    HANDLE process = nullptr;
    HANDLE thread = nullptr;
};

[[nodiscard]] // if value is ignored in calling function, compiler will warn (good practice)
LaunchResult launchExe(const std::wstring& exePath, const std::vector<std::wstring>& argv, const std::wstring& cmd = L"");

[[nodiscard]]
DWORD shellOpen(const std::wstring& target, const std::wstring& parameters = L"", const std::wstring& cmd = L"", const std::wstring& verb = L"open", int show = SW_SHOWNORMAL);

