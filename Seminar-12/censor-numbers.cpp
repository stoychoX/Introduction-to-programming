#include <iostream>

unsigned myStrlen(const char* text)
{
	if (text == nullptr) { return 0; }

	unsigned count = 0;
	while (*text != '\0')
	{
		++count;
		++text;
	}
	return count;
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

unsigned countDigits(const char* text)
{
    if(text == nullptr) { return 0; }
	unsigned count = 0;
	while (*text != '\0')
	{
		if (isDigit(*text))
		{
			++count;
		}
		++text;
	}
	return count;
}

unsigned countNumbers(const char* text)
{
    if(text == nullptr) { return 0; }

	unsigned counter = 0;
	while (*text != '\0')
	{
		if (isDigit(*text) && !isDigit(*(text + 1)))
		{
			++counter;
		}
		++text;
	}
	return counter;
}

char* censorNumbers(const char* text)
{
    if(text == nullptr) { return nullptr; }

	unsigned len = myStrlen(text);
	unsigned digitsCount = countDigits(text);
	unsigned numbersCount = countNumbers(text);

	unsigned resultLenght = len - digitsCount + numbersCount;

	char* toReturn = new char[resultLenght + 1];
	unsigned pos = 0;

	while (*text != '\0')
	{
		if (!isDigit(*text))
		{
			toReturn[pos++] = *text;
		}
		else if (isDigit(*text) && !isDigit(*(text + 1)))
		{
			toReturn[pos++] = '*';
		}
		++text;
	}
	toReturn[pos] = '\0';
	return toReturn;
}

int main()
{
    const char* example = "12This is 145 example 1 text 145";

    char* censored = censorNumbers(example);
    std::cout << censored;
    delete[] censored;
}