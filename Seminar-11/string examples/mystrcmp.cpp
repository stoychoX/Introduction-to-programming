#include <iostream>

// сравнява два стринга лексикографски
// -1 означава, че str1 < str2
// 0 означава, че са равни
// 1 означава, че str1 > str2
int myStrcmp(const char* str1, const char* str2)
{
    if(str1 == nullptr || str2 == nullptr)
    {
        return 0;   // some error value
    }

    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        ++str1; ++str2;
    }
    // Тук можем да спестим тези if конструкции
    // return (*str1 > *str2) - (*str1 < *str2); защо това работи???

    if(*str1 > *str2)
    {
        return 1;
    }
    
    if(*str1 < *str2)
    {
        return -1;
    }

    return 0;
}

int main()
{
    const char* firstString = "Hello, my name is Stoycho";
    const char* secondString = "Hello, my name is Yavor";

    std::cout << myStrcmp(firstString, secondString);
}