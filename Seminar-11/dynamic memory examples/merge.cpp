#include <iostream>

void print(const int* arr, unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int* merge(const int* left, unsigned leftSize, const int* right, unsigned rightSize)
{
    int* toReturn = new int[leftSize + rightSize];

    unsigned leftIter = 0;
    unsigned rightIter = 0;
    unsigned resultIter = 0;

    while(leftIter < leftSize && rightIter < rightSize)
    {
        if(left[leftIter] < right[rightIter])
        {
            toReturn[resultIter++] = left[leftIter++];
        }
        else
        {
            toReturn[resultIter++] = right[rightIter++];
        }
    }

    while(leftIter < leftSize)
    {
        toReturn[resultIter++] = left[leftIter++];
    }

    while(rightIter < rightSize)
    {
        toReturn[resultIter++] = right[rightIter++];
    }

    return toReturn;
}

int main()
{
    int first[7] = {1, 2, 4, 8, 16, 32, 64};
    int second[9] = {1, 3, 7, 10, 11, 29, 69, 71, 100};

    int* merged = merge(first, 7, second, 9);

    print(merged, 16);

    // !!!!
    delete[] merged;
}