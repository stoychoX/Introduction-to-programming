#include <iostream>

bool isPreffix(const char* str1, const char* str2)
{
    while(*str2 != '\0' && *str1 == *str2)
    {
        ++str1; ++str2;
    }

    return (*str2 == '\0');
}

const char* findInText(const char* text, const char* pattern)
{
    while(*text != '\0')
    {
        if(isPreffix(text, pattern))
        {
            return text;
        }
        ++text;
    }

    return nullptr;
}

int main()
{
    const char* text = "Hello world";
    const char* pattern = "world";

    std::cout << findInText(text, pattern);
}