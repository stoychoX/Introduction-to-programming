#include <iostream>

char* myStrcat(char* destination, const char* source)
{
    if(destination == nullptr || source == nullptr) 
    {
        return nullptr;
    }

    char* toReturn = destination;
    while(*destination != '\0') 
    {
        ++destination;
    }

    while (*source != '\0')
    {
        *destination = *source;
        ++destination;
        ++source;
    }
    *destination = '\0';

    return toReturn;
}

int main()
{
    char buff[100] = "Hello, my name is ";
    const char* name = "Stoycho";
    char* result = myStrcat(buff, name);
    std::cout << buff; // еквивалентно на std::cout << result
}