#include <iostream>

using namespace std;

constexpr unsigned MAX_LENGTH = 1024 + 1;

bool isValidInput(unsigned first, unsigned second)
{
	return first < MAX_LENGTH && second < MAX_LENGTH && (first <= second);
}

void readInterval(unsigned& first, unsigned& second)
{
	bool failedInput = false;
	do
	{
		if (failedInput)
		{
			cout << "Invalid input" << endl;
		}

		cin >> first >> second;
		failedInput = true;
	} while (!isValidInput(first, second));
}

void mark(unsigned numberOccurance[], unsigned first, unsigned second)
{
	for (size_t i = first; i <= second; i++)
	{
		numberOccurance[i]++;
	}
}

void printSolution(unsigned numberOccurance[])
{
	for (size_t i = 0; i < MAX_LENGTH; i++)
	{
		if (numberOccurance[i] != 0)
		{
			cout << i << " " << numberOccurance[i] << endl;
		}
	}
}

void solve(unsigned intervalsCount)
{
	unsigned first = 0;
	unsigned second = 0;

	unsigned numberOccurance[MAX_LENGTH] = { 0 };

	for (size_t i = 0; i < intervalsCount; i++)
	{
		readInterval(first, second);
		mark(numberOccurance, first, second);
	}

	printSolution(numberOccurance);
}


int main()
{
    unsigned n = 0;
    cin >> n;
    solve(n);
}