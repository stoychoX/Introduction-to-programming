#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int* arr, unsigned lenght)
{
    for (size_t i = 0; i < lenght; i++)
    {
        size_t minElementIndex = i;
        for (size_t j = i + 1; j < lenght; j++)
        {
            if(arr[j] < arr[minElementIndex])
            {
                minElementIndex = j;
            }
        }

        if(i != minElementIndex) 
        { 
            swap(arr[i], arr[minElementIndex]); 
        }
    }
}

int main()
{
    int arr[] = {1, 5, 4, 2, 3, 6};
    selectionSort(arr, 6);
}