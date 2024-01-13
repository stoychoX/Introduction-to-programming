#include <iostream>

unsigned countOccurances(const char* text, unsigned symbol)
{
    unsigned count = 0;
    while (*text)
    {
        if(*text == symbol)
        {
            ++count;
        }
        ++text;
    }
    return count;
}

char* myStrcpy(char* dest, const char* src, unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}

char* getNextWord(const char* text, unsigned wordSize)
{
    char* word = new char[wordSize + 1];
    const char* wordBeginning = text - wordSize;
    myStrcpy(word, wordBeginning, wordSize);
    
    return word;
}

char** split(const char* text, char symbol, unsigned& size)
{
    size = countOccurances(text, symbol) + 1;
    char** dict = new char*[size];
    unsigned currentWordSize = 0;
    unsigned pos = 0;

    while(*text)
    {
        if(*text != symbol)
        {
            ++currentWordSize;
        }
        else
        {
            dict[pos++] = getNextWord(text, currentWordSize);
            currentWordSize = 0;
        }
        ++text;
    }

    // Handle last word
    dict[pos] = getNextWord(text, currentWordSize);

    return dict;
}

void free(char** dict, unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] dict[i];
    }
    delete[] dict;
}

void print(char** dict, unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << dict[i] << std::endl;
    }
}

int main()
{
    const char* example = "Hello, this is an example text!";
    unsigned size = 0;
    char** dict = split(example, ' ', size);

    print(dict, size);
    free(dict, size);
}