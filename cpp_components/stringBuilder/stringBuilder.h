#pragma once

#define SB_MAX_CHAR_NUMBER 99

#include <iostream>
#include <cstring>

class stringBuilder
{
    protected:
        int currentChar = 0;
        char buff[SB_MAX_CHAR_NUMBER+1];
		std::string s;
    public:
        stringBuilder();
        void add(char c);
		std::string build();
        void clean();
};
