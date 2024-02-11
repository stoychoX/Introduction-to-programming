#include<iostream>

unsigned countDigits(unsigned number)
{
	if (number == 0)
		return 1;
	unsigned count = 0;
	while (number)
	{
		++count;
		number /= 10;
	}
	return count;
}

char* numberToString(unsigned number)
{
	unsigned digitsCount = countDigits(number);
	char* toReturn = new char[digitsCount + 1];
	
	toReturn[digitsCount] = '\0';

	while (digitsCount > 0)
	{
		unsigned lastDigit = number % 10;
		number /= 10;

		toReturn[digitsCount - 1] = lastDigit  + '0';
		--digitsCount;
	}

	return toReturn;
}

char* readNumberAsString()
{
	unsigned currentNumber = 0;
	std::cin >> currentNumber;
	return numberToString(currentNumber);
}

int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
		return 0;

	while ((*first) && (*second) && ((*first) == (*second))) //acutally the (*second) check can be missed here.
	{
		first++;
		second++;
	}

	return (*first - *second);
}

void swap(char*& fst, char*& snd)
{
	char* temp = fst;
	fst = snd;
	snd = temp;
}

void sortStrings(char** words, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		size_t minIndex = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (myStrcmp(words[j], words[minIndex]) < 0)
				minIndex = j;
		}

		if (minIndex != i) 
			swap(words[i], words[minIndex]);
	}
}

void freeWords(char** words, size_t size)
{
	for (size_t i = 0; i < size; i++)
		delete[] words[i];
	delete[] words;
}

int main()
{
	size_t numbersCount = 0;
	std::cin >> numbersCount;

	char** stringRepresentedNumbers = new char* [numbersCount];

	for (size_t i = 0; i < numbersCount; i++) {
		stringRepresentedNumbers[i] = readNumberAsString();
	}

	sortStrings(stringRepresentedNumbers, numbersCount);

	for (size_t i = 0; i < numbersCount; i++) {
		std::cout << stringRepresentedNumbers[i] << std::endl;
	}

	freeWords(stringRepresentedNumbers, numbersCount);
}