#include <iostream>

void getMaxAndMinDigit(int number, int& min, int& max)
{
	int minDigit = 9;
	int maxDigit = 0;

	while (number != 0)
	{
		int lastDigit = number % 10;
		number /= 10;

		if (lastDigit < minDigit) 
		{
			minDigit = lastDigit;
		}
		if (lastDigit > maxDigit)
		{
			maxDigit = lastDigit;
		}
	}

	min = minDigit;
	max = maxDigit;
}


int main()
{
	int min = 0;
	int max = 0;

	getMaxAndMinDigit(12345, min, max);

	std::cout << min << " " << max;
}