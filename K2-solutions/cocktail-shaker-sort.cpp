
#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void cocktailShakerSort(int* arr, size_t length)
{
	int lowerSwappedIndex = 0;
	int upperSwappedIndex = length - 1;

	unsigned iterationsNeeded = length / 2;

	for (size_t i = 0; i < iterationsNeeded; i++)
	{
		int tempLower = lowerSwappedIndex;
		int tempUpper = upperSwappedIndex;

		for (size_t j = tempLower; j < tempUpper; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				upperSwappedIndex = j;
			}
		}

		if (tempUpper == upperSwappedIndex) 
		{ 
			break; 
		}

		for (int j = tempUpper; j > tempLower; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				lowerSwappedIndex = j;
			}
		}

		if (tempLower == lowerSwappedIndex) 
		{ 
			break; 
		}
	}
}

int main()
{
	int v[] = {0, 4, 3, 5, 2, 6, 9, 8, 7, 11};

	cocktailShakerSort(v, 10);

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << v[i] << " ";
	}
}