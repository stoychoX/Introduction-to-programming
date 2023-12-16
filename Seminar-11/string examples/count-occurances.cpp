#include <iostream>

unsigned countSymbolOccurances(const char* text, char symbol)
{
    unsigned counter = 0;
    while(*text != '\0')
    {
        if(*text == symbol)
        {
            ++counter;
        }
        ++text;
    }
    return counter;
}

int main()
{
    const char* text = "this is my sample text";
    std::cout << countSymbolOccurances(text, 't');
}