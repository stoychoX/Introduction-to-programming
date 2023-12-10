#include <iostream>
#include <cstring>
size_t myStrlen(const char* str)
{
    size_t counter = 0;
    while (*str != '\0')
    {
        ++counter;
        ++str;
    }
    return counter;
}

int main()
{
    const char* str = "Hello string functionallity";
    std::cout << "The length of the text \"" << str << "\" is " << myStrlen(str);
}