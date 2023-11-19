#include <iostream>

int binarySearch(const int arr[], unsigned length, int elem)
{
    int left = 0;
    int rigth = length - 1;

    while (rigth - left > 0)
    {
        int mid = left + (rigth - left) / 2;

        if(arr[mid] == elem)
        {
            return mid;
        }
        else if (arr[mid] > elem)
        {
            left = mid + 1;
        }
        else
        {
            rigth = mid - 1;
        }
    }

    return -1;
}

int main()
{
    
}