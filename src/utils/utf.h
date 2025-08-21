#pragma once
#include<string>

std::wstring Utf8ToWide(std::string_view CommandString); // converting to Wide/UTF16 allows for other languages and Emojis and what not --> probably unnecessary but cool all the same.