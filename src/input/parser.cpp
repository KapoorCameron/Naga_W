#include<iomanip>
#include<sstream>
#include<string>
#include<vector>

#include"parser.h"

// We need to be able to take quoted arguments 

Command parse(std::string input)
{
    Command cmd;
    std::istringstream iss(input);
    std::string arg;

    bool firstArg = true;
    while (iss >> std::quoted(arg))
    {
        if (firstArg)
        {
            cmd.name = arg;
            firstArg = false;
        }

        else
        {
            cmd.args.push_back(arg);
        }
    }

    return cmd;
}