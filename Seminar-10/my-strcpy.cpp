#include <iostream>

// Копира source в destination.
// След изпълнение на тази функция destination и source
// имат една и съща стойност!
char* myStrcpy(char* destination, const char* source)
{
    char* toReturn = destination;

    while(*source != '\0')
    {
        *destination = *source;
        ++source;
        ++destination;
    }

    *destination = '\0';
    return toReturn;
}

int main()
{
    char destination[] = "This is some text.";
    const char* src = "New text value";

    char* result = myStrcpy(destination, src);

    // Можем да използваме result или destination и двете сочат към едно и също място.

    std::cout << "After we copy source to destination the new value of destination is " << destination << " or we can use the pointer "
              << "returned by the function: " << result;
}