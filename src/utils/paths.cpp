#include<filesystem>
#include<iostream>
#include<string>

#include"paths.h"

std::filesystem::path previous_dir;

std::filesystem::path getCWD()
{
    return std::filesystem::current_path();
}

bool setCWD(const std::filesystem::path& path)
{
    previous_dir = getCWD();

    try 
    {
        std::filesystem::path p = resolvePath(path.string());
        std::filesystem::current_path(p);
        return true;
    }

    catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return false;
    }
}

bool getPreviousDirectory()
{
    std::filesystem::path newPrevious = getCWD();

    if (!previous_dir.empty())
    {
        bool success = setCWD(previous_dir.string());
        if (success)
        {
            previous_dir = newPrevious;
        }

        else
        {
            std::cerr << "Error: previous directory exists but is invalid.\n";
        }
        return success;
    }

    else
    {
        std::cerr << "Error: no previous directory.\n";
        return false;
    }
}

std::filesystem::path getHomeDirectory()
{
    const char* home = std::getenv("USERPROFILE"); // const char* bc env var is a c-style string 
    if (home)
    {
        return std::filesystem::path(home);
    }
    
    else
    {
        std::cerr << "Error: HOME directory not found.\n";
        return getCWD();
    }
}

std::filesystem::path resolvePath(const std::string& path) // converts string into legitimate path
{
    std::filesystem::path p = path; // we turn std::string path into a veritable path variable

    if (!p.empty() && path[0] == '~')
    {
        p = std::filesystem::path(std::getenv("USERPROFILE")) / p.relative_path().string().substr(1);
    }

    return std::filesystem::absolute(p.lexically_normal());
}

std::filesystem::path joinPath(const std::string& base, const std::string& relative) // to properly join paths with "\"
{
    return std::filesystem::path(base) / std::filesystem::path(relative); // "/" is overloaded-- automatically uses platform-specific separator ("\" in Windows)
}


