#include "stringBuilder.h"

stringBuilder::stringBuilder()
{
    currentChar = 0;
    buff[SB_MAX_CHAR_NUMBER] = (char)NULL;
    s = "";
}

void stringBuilder::add(char c)
{
    if(SB_MAX_CHAR_NUMBER > currentChar)
    {
        buff[currentChar] = c;
        currentChar++;
    }
    else
    {
        s += buff;
        buff[0] = c;
        currentChar = 1;
    }
}

std::string stringBuilder::build()
{
    buff[currentChar] = (char)NULL;
    s += buff;
    return s;
}

void stringBuilder::clean()
{
    std::memset(buff, (char)NULL, SB_MAX_CHAR_NUMBER);
    s = "";
    currentChar = 0;
}
