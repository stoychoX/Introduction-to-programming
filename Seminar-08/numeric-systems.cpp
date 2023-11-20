#include <iostream>

char toUpper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return ch - ('a' - 'A');
	}
	return ch;
}

char toLower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return ch + ('a' - 'A');
	}

	return ch;
}

bool isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

// Error handling functions:
void displayOutOfBound(unsigned number)
{
	std::cout << "The passed number " << number << " exceeds the bounds of the array." << std::endl;
}

void displayInvalidDigit(char digit)
{
	std::cout << "The passed digit " << digit << " is not well defined." << std::endl;
}

// Helper functions:
char getDigit(unsigned digit)
{
	if (digit < 10)
	{
		return '0' + digit;
	}
	else if (digit <= 36)
	{
		return 'A' + (digit - 10);
	}

	// '\0' is the char symbol represented as 0.
	return '\0';
}

// Returns numeric value for digit represented as char.
// Digits aren't only the standard digits [0..9] but we use
// A to represent 10
// B to represent 11
// etc
unsigned getNumber(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return ch - 'A' + 10;
	}
	return -1;
}

// Версиите на решението което не "обръщат" числото в масива
// т.е. когато имаме 6 в масива за двоична бройна система ще е записано {'1', '1', '0'}

//"from" is in K numeral system. The function converts it to decimal (and the result is stored in an int)
unsigned int fromRandomToDecimal(const char from[], size_t size, unsigned k)
{
	int result = 0;

	for (int i = size - 1, mult = 1; i >= 0; i--, mult *= k) //we declare both the array iter (variable i) and mult in the loop
		result += getNumber(from[i]) * mult;
	return result;
}


//converts number from decimal to a number in K numeral system. The result is stored in the array "to"
void fromDecimalToRandom(unsigned n, char to[], size_t size, unsigned k)
{
	for (int arrayIter = size - 1; arrayIter >= 0; arrayIter--) //we fill the array backwards!
	{
		int ind = n % k;
		char current = getDigit(ind);
		to[arrayIter] = current;
		n /= k;
	}
}

// Версията на функциите които "обръщат" числото в масива.
// т.е. когато имаме 6 в масив за двоична бройна система ще е записано {'0', '1', '1'}

// returns the number of digits of the number 
// bufferSize is the size of the array
int fromDecimal(unsigned number, unsigned base, char result[], unsigned bufferSize)
{
	int size = 0;
	while (number != 0)
	{
		if (bufferSize <= size)
		{
			displayOutOfBound(number);
			return -1;
		}

		unsigned lastDigit = number % base;
		result[size] = getDigit(lastDigit);
		number = number / base;
		size++;
	}

	return size;
}


// returns the number represented from `number` in base `base`
// in decimal.
unsigned toDecimal(char number[], unsigned size, unsigned base)
{
	unsigned result = 0;
	unsigned exponent = 1;

	for (unsigned i = 0; i < size; i++)
	{
		unsigned currentNumber = getNumber(number[i]);
		
		if (currentNumber == -1)
		{
			displayInvalidDigit(number[i]);
			return -1;
		}

		result += currentNumber * exponent;
		exponent *= base;
	}

	return result;
}

// Converts number in k-numeric sysytem to number of n-numeric system.
// returns the number of digits of the new number.
unsigned convertNumericSystems(char numberKNumeric[], unsigned sizeKNumeric, unsigned baseKNumeric, char numberNNumeric[], int sizeNNumeric, unsigned baseNNumeric)
{
	unsigned decimalNumber = toDecimal(numberKNumeric, sizeKNumeric, baseKNumeric);
	unsigned numberOfDigits = fromDecimal(decimalNumber, baseNNumeric, numberNNumeric, sizeNNumeric);

	return numberOfDigits;
}

void showNumber(char number[], unsigned size, unsigned originalNumber, unsigned base)
{
	std::cout << "The number " << originalNumber << " is ";
	for (int i = size - 1; i >= 0; i--) { std::cout << number[i]; }
	std::cout << " in base " << base << " numeric system" << std::endl;
}

int main()
{
	constexpr unsigned NUMBER_MAX_LEN = 100;
	
	// Original number:
	unsigned number = 12648430;


	// Convert it to base 16:
	char hexadecimalNumber[NUMBER_MAX_LEN] = {};
	unsigned resultLen = fromDecimal(number, 16, hexadecimalNumber, NUMBER_MAX_LEN);
	showNumber(hexadecimalNumber, resultLen, number, 16);


	// Convert the base 16 number to base 2:
	char binaryNumber[NUMBER_MAX_LEN] = {};
	unsigned binaryNumberLength = convertNumericSystems(hexadecimalNumber, resultLen, 16, binaryNumber, NUMBER_MAX_LEN, 2);
	showNumber(binaryNumber, binaryNumberLength, number, 2);


	// Convert the base 2 to base 36:
	char baseThirtySixNumber[NUMBER_MAX_LEN] = {};
	unsigned baseThirtySixLen = convertNumericSystems(binaryNumber, binaryNumberLength, 2, baseThirtySixNumber, NUMBER_MAX_LEN, 36);
	showNumber(baseThirtySixNumber, baseThirtySixLen, number, 36);


	// Get beck to the original number:
	unsigned originalNumber = toDecimal(binaryNumber, binaryNumberLength, 2);
	std::cout << "Started from " << number << " and got to " << originalNumber;
}