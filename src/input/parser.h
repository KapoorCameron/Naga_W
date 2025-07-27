#pragma once

#include<string>
#include<vector>

struct Command
{
    std::string name; // "cd", "mkdir", "echo"
    std::vector<std::string> args;
};

Command parse(std::string input);