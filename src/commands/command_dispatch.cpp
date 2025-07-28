#include<functional>
#include<iostream>
#include<unordered_map>

#include"command_dispatch.h"

void getCommand(const Command& cmd) // use a function map/command map
{
    static const std::unordered_map<std::string, std::function<void(const Command&)>> commandMap = 
    {
        {"help", execute_help},
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