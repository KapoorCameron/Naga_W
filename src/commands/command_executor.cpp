#include<algorithm>
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>

#include"command_executor.h"

void execute_help(const Command& cmd)
{
    std::vector<std::pair<std::string, std::string>> commands =
    {
        {"help", "Displays commands list."},
        {"exit/quit", "Quits program"},
        {"case", "Toggles case sensitivity"},
    };

    std::sort(commands.begin(), commands.end());
    
    std::cout << "\n//For command-specific details, enter \"help (command name)\"\\\\\n";

    for (const auto& [command_name, description] : commands)
    {
        std::cout << std::left << std::setw(16) << command_name << description << "\n";
    }
    std::cout << "\n";
}