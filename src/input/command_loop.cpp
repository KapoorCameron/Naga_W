#include<iostream>
#include<string>

#include"command_loop.h"
#include"parser.h"

void commandLoop()
{
    std::cout << "Naga_W v25.07.26\n\n";

    std::string input;
    bool run = true;
    while (run)
    {
        std::cout << "&>>";
        std::getline(std::cin, input);

        if (input == "exit" || input == "quit" || input == "cuidate")
        {
            std::cout << "Exiting...\n"; 
            break;
        }

        Command cmd = parse(input); // struct Command and parse(string) from parser.h

        
    }
}