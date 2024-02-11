#include <iostream> 

bool isDigit(char ch) 
{
    return ch >= '0' && ch <= '9';
}

unsigned lognesrNumber(const char* str, unsigned currentNumLen = 0, unsigned maxNumLen = 0)
{
    maxNumLen = std::max(maxNumLen, currentNumLen);
    if(!*str)
        return maxNumLen;
    if(isDigit(*str))
        currentNumLen++;
    else
        currentNumLen = 0;
 
    return lognesrNumber(str + 1, currentNumLen, maxNumLen); 
}

int main()
{
    std::cout << lognesrNumber("abc123edsfds3fsd1");
}