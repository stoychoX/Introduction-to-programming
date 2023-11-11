#include<iostream>

using namespace std;

unsigned reverseNumber(unsigned numberToReverse)
{
	unsigned flippedNumber = 0;

	while (numberToReverse != 0)
	{
		flippedNumber *= 10;
		flippedNumber += numberToReverse % 10;
		numberToReverse = numberToReverse / 10;
	}
	return flippedNumber;
}

unsigned countDigits(unsigned number)
{
	if(number == 0)
		return 1;
	unsigned counter = 0;

	while (number != 0)
	{
		number /= 10;
		counter++;
	}
	return counter;
}

bool isPalindrome(unsigned x)
{
	unsigned reversed = reverseNumber(x);
	return (x == reversed);
}

unsigned sumInInterval(unsigned m, unsigned n)
{
	if (m > n)
	{
		return 0;
	}

	unsigned sum = 0;

	for (unsigned i = m; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

// sum([1, ..., x]) = x * (x + 1) / 2
// sum([m, ..., n]) = sum([1, ..., n]) - sum([1, ..., m])
unsigned sumInIntervalSmart(unsigned m, unsigned n)
{
    if(m > n)
    {
        return 0;
    }

    --m;

    return (n * (n + 1) / 2) - (m * (m + 1) / 2);
}
#include<cassert>
int main()
{
    for (size_t i = 0; i < 1000000; i++)
    {
        int fst = rand();
        int snd = rand();
        assert(sumInInterval(fst, snd) == sumInIntervalSmart(fst, snd));
    }
    
}
