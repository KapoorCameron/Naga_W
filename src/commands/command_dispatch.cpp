#include<functional>
#include<iostream>
#include<unordered_map>

#include"command_dispatch.h"

// The function map/command map that we use to call commands into which we pass cmd.name and cmd.args 

void getCommand(const Command& cmd)
{
    static const std::unordered_map<std::string, std::function<void(const Command&)>> commandMap = 
    {
        {"cd"  , execute_cd},
        {"go"  , execute_go},
        {"help", execute_help},
        {"parseltongue", execute_secret},
        
    };

    auto command = commandMap.find(cmd.name);

    if (command != commandMap.end())
    {
        command->second(cmd);
    }

    else
    {
        std::cout << "-INVALID COMMAND-\n";
    }
}