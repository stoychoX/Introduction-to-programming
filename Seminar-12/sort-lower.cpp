#include <iostream>

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

unsigned getLowerCount(const char* text)
{
	unsigned counter = 0;
	while (*text != '\0')
	{
		if (isLower(*text))
		{
			++counter;
		}
		++text;
	}
	return counter;
}

void fillSymbols(char* temp, unsigned times, unsigned& pos, char symbol)
{
	for (size_t i = 0; i < times; i++)
	{
		temp[pos++] = symbol;
	}
}

char* getLowerSorted(const char* text)
{
	unsigned lowerCount = getLowerCount(text);
	char* toReturn = new char[lowerCount + 1];
	int hist[26] = {};

	while (*text != '\0')
	{
		if (isLower(*text))
		{
			unsigned index = *text - 'a';
			++hist[index];
		}
		++text;
	}
	unsigned pos = 0;
	for (size_t i = 0; i < 26; i++)
	{
		fillSymbols(toReturn, hist[i], pos, 'a' + i);
	}
	toReturn[pos] = '\0';
	return toReturn;
}

int main()
{
    const char* example = "this is An example Text";
    char* sortedLower = getLowerSorted(example);

    std::cout << sortedLower;

    delete[] sortedLower;
}