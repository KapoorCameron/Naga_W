#include<algorithm>
#include<cctype>
#include<string>

#include"string_utils.h"

void trim(std::string& input)
{
    // Goes left to right until first non-::isspace char:
    std::string::const_iterator start = std::find_if_not(input.begin(), input.end(), ::isspace);

    // Goes right to left until first non-::isspace character, .base() flips to be L to R:
    std::string::const_iterator end = std::find_if_not(input.rbegin(), input.rend(), ::isspace).base();

    input = (start < end) ? std::string(start, end) : "";
}

void to_lower(std::string& input)
{
    for (char& c : input)
    {
        if (c >= 65 && c <= 90)
        {
            c += 32;
        }
    }
}