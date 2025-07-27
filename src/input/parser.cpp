#include<sstream>
#include<string>
#include<vector>

#include"parser.h"

Command parse(std::string input)
{
    Command cmd;
    std::istringstream iss(input);
    std::string token;
    std::vector<std::string> tokens;

    while (iss >> token)
    {
        tokens.push_back(token);
    }

    cmd.name = tokens[0];
    for (int i = 1; i < tokens.size(); i++)
    {
        cmd.args.push_back(tokens[i]);
    }

    return cmd;
}