#include<algorithm>
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>

#include"../w_lean.h"

#include"../utils/paths.h"
#include"command_executor.h"

// Here, we parse cmd for cmd.name and cmd.args to execute appropriate function as specified

void execute_cd(const Command& cmd)
{
    if (cmd.args.empty())
    {
        setCWD(getHomeDirectory());
    }

    else if (cmd.args[0] == "-")
    {
        getPreviousDirectory(); 
    }

    else
    {
        setCWD(cmd.args[0]);
    }
}

// void execute_go(const Command& cmd)
// {
    
// }

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

    // "auto" is type: const std::pair<std::string, std::string>&
    for (const auto& [command_name, description] : commands)
    {
        std::cout << std::left << std::setw(16) << command_name << description << "\n";
    }
    std::cout << "\n";
}

void execute_secret(const Command& cmd)
{
    // list UI commands for later: commands to change theme, play music, 
}

