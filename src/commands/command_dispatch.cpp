#include<functional>
#include<iostream>
#include<unordered_map>

#include"command_dispatch.h"

// The function map/command map that we use to call commands into which we pass cmd.name and cmd.args 

void getCommand(const Command& cmd)
{
    static const std::unordered_map<std::string, std::function<void(const Command&)>> commandMap = 
    {
        {"help", execute_help},
        {"cd"  , execute_cd},
    };

    auto command = commandMap.find(cmd.name);

    if (command != commandMap.end())
    {
        command->second(cmd);
    }

    else
    {
        std::cout << "INVALID COMMAND\n";
    }
}