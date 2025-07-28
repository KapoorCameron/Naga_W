#include<iostream>
#include<string>

#include"../commands/command_dispatch.h"
#include"../utils/string_utils.h"

#include"command_loop.h"
#include"parser.h"

void commandLoop()
{
    std::cout << "Naga\\W v25.07.26\n\n";

    std::string input;
    bool run = true; // a little redundant now, but possible uses later
    bool caseSensitive = false; 
    while (run)
    {
        std::cout << "&_>> "; 
        std::getline(std::cin, input);

        trim(input); // from src/utils/string_utils.h 
        if (!caseSensitive)
        {
            to_lower(input); // from src/utils/string_utils.h
        }

        if (input == "case")
        {
            caseSensitive = !caseSensitive;
            std::cout << "System is case-" << (caseSensitive ? "sensitive\n" : "insensitive\n");
            continue;
        }

        if (input == "exit" || input == "quit" || input == "cuidate")
        {
            std::cout << "Exiting...\n"; 
            break;
        }

        else if (input == "test")
        {
            std::cout << "booyah\n";
            continue;
        }

        Command cmd = parse(input); // struct Command and parse(string) from parser.h

        getCommand(cmd); // getCommand from src/commands/command_dispatch.h
    }
}