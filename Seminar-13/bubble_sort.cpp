#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int* arr, unsigned length)
{
    size_t lastSwappedIndex = length - 1;

    for (size_t i = 0; i < length; i++)
    {
        unsigned lastSwappedIndexTemp = lastSwappedIndex;
        for (size_t j = 0; j < lastSwappedIndex; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                lastSwappedIndexTemp = j;
            }
        }

        if(lastSwappedIndex == lastSwappedIndexTemp) { break; }
        lastSwappedIndex = lastSwappedIndexTemp;
    }
}

int main()
{
    int arr[] = {5, 2, 3, 1, 4};
    bubbleSort(arr, 5);
}