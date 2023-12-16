#include <iostream>
#include <cstring>

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int myAtoi(const char* string)
{
    if(string == nullptr)
    {
        return 0;
    }

    bool isNegative = (*string == '-');
    if(isNegative) ++string;

    if(*string == '+') ++string;

    int number = 0;
    while(*string != '\0')
    {
        if(!isDigit(*string)) return 0;

        number *= 10;
        number += *string  - '0';
        ++string;
    }

    return isNegative ? -number : number;
}

int main()
{
}