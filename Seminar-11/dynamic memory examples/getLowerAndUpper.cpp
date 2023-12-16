#include <iostream>

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

unsigned countLower(const char* text)
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

unsigned countUpper(const char* text)
{
	unsigned counter = 0;

	while (*text != '\0')
	{
		if (isUpper(*text))
		{
			++counter;
		}
		++text;
	}
	return counter;
}


void getLowerAndUpperLetters(const char* text, char*& lower, char*& upper)
{
	if (text == nullptr)
		return;
	unsigned lowerSymbols = countLower(text) + 1;
	unsigned upperSymbols = countUpper(text) + 1;

	lower = new char[lowerSymbols]; // terminating zero
	upper = new char[upperSymbols];

	unsigned lowerIter = 0;
	unsigned upperIter = 0;

	while (*text != '\0')
	{
		if (isLower(*text))
		{
			lower[lowerIter++] = *text;
		}
		else if (isUpper(*text))
		{
			upper[upperIter++] = *text;
		}
		++text;
	}
	
	lower[lowerIter] = '\0';
	upper[upperIter] = '\0';
}

int main()
{
	const char* ch = "145textTEXTtext";
	char* lower, * upper;
	getLowerAndUpperLetters(ch, lower, upper);
	std::cout << lower << " " << upper;

    delete[] lower;
    delete[] upper; // !!!
}