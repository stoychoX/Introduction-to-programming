#include <iostream>

bool isWordSymbol(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// брой думи = брой символи от зададената азбука, които се следват от символ извън нея.
unsigned wordsCount(const char* text)
{
    unsigned count = 0;
    while (*text)
    {
        if(isWordSymbol(*text) && !isWordSymbol(*(text + 1)))
        {
            ++count;
        }
        ++text;
    }
    return count;
}

void skipSymbols(const char*& text)
{
    while (*text && !isWordSymbol(*text))
    {
        ++text;
    }
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

char* getNextWord(const char*& text)
{
    unsigned wordSize = 0;
    while (isWordSymbol(*text))
    {
        ++text;
        ++wordSize;
    }
    char* word = new char[wordSize];
    const char* wordBeginning = text - wordSize;
    myStrcpy(word, wordBeginning, wordSize);
    return word;
}

// Дума: последователност от малки и главни латински букви.
// Идея: докато имаме символи в поддадения низ:
//      1. махни всички символи, които не са от азбуката
//      2. махни всички символи от азбуката и ги добави като нова дума
char** splitWords(const char* text, unsigned& size)
{
    size = wordsCount(text);
    char** dict = new char*[size];
    unsigned pos = 0;

    while(*text)
    {
        skipSymbols(text);
        dict[pos++] = getNextWord(text);
    }
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
    const char* example = " !!! this Is ! ! ! example ))0 an example ... a";
    unsigned size = 0;
    char** dict = splitWords(example, size);
    print(dict, size);
    free(dict, size);
}