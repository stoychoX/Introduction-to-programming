#include <iostream>

bool binarySearchRec(int* arr, int left, int right, int needle)
{
    if(right < left)
    {
        return false;
    }

    int mid = left + (right - left) / 2;

    if(arr[mid] == needle)
    {
        return true;
    }
    else if(arr[mid] > needle)
    {
        return binarySearchRec(arr, left, mid - 1, needle);
    }
    return binarySearchRec(arr, mid + 1, right, needle);
}

bool binarySearch(int* arr, size_t size, int needle)
{
    return binarySearchRec(arr, 0, size - 1, needle);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (size_t i = 0; i < 11; i++)
    {
        std::cout << binarySearch(arr, 9, i) << std::endl;
    }
}