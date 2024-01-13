#include <iostream>

void countSymbols(const char* text, unsigned histogram[26])
{
	while (*text != '\0')
	{
		histogram[(*text - 'a')]++;
		++text;
	}
}

void buildPalindrome(char* palindrome, char symbol, unsigned occurances, unsigned stringLenght, unsigned& currentPos)
{
	while (occurances > 1)
	{
		palindrome[currentPos] = palindrome[stringLenght - currentPos - 1] = symbol;
		occurances -= 2;
		currentPos++;
	}

    // corner case for odd symbol
	if (occurances == 1)
	{
		palindrome[stringLenght / 2] = symbol;
	}
}

char* isPalindrome(const char* firstString, const char* secondString)
{
	unsigned histogram[26] = {};
	countSymbols(firstString, histogram);
	countSymbols(secondString, histogram);

	bool seenOdd = false;
	unsigned resultStringLength = 0;

	for (size_t i = 0; i < 26; i++)
	{
		resultStringLength += histogram[i];

		if (histogram[i] % 2 == 1)
		{
			if (seenOdd)
			{
				return nullptr;
			}
			seenOdd = true;
		}
	}

	char* palindrome = new char[resultStringLength + 1];
	unsigned currentPos = 0;
	
	for (size_t i = 0; i < 26; i++)
	{
		buildPalindrome(palindrome, i + 'a', histogram[i], resultStringLength, currentPos);
	}
	palindrome[resultStringLength] = '\0';
	return palindrome;
}

int main()
{
    char* result = isPalindrome("hello", "eh");

    if(result == nullptr)
    {
        std::cout << "No palindrome can be formed";
    }
    else
    {
        std::cout << result;
        delete[] result;
    }
}