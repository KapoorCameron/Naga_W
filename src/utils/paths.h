#pragma once

#include<filesystem>

std::filesystem::path getCWD();
bool setCWD(const std::filesystem::path& path);
bool getPreviousDirectory();
std::filesystem::path getHomeDirectory();
std::filesystem::path resolvePath(const std::string& path);
std::filesystem::path joinPath(const std::string& base, const std::string& relative);
