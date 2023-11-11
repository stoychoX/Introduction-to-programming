#include <iostream>

unsigned countOccurances(unsigned number, unsigned digit)
{
	unsigned counter = 0;

	while (number != 0)
	{
		unsigned lastDigit = number % 10;
		number /= 10;
		if (lastDigit == digit)
		{
			++counter;
		}
	}

	return counter;
}

unsigned appendBack(unsigned number, unsigned digit)
{
    number *= 10;
    number += digit;
    return number;
}

unsigned appendDigits(unsigned number, unsigned digit, unsigned times)
{
    for (size_t i = 0; i < times; i++)
    {
        number = appendBack(number, digit);
    }
    return number;
}

unsigned sortDigits(unsigned number)
{
	unsigned toReturn = 0;

	for (unsigned i = 1; i < 10; i++)
	{
		unsigned count = countOccurances(number, i);
        toReturn = appendDigits(toReturn, i, count);
	}

	return toReturn;
}

int main()
{
    unsigned number = 0;
    std::cin >> number;
    number = sortDigits(number);
    std::cout << number;
}