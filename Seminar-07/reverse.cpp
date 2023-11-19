#include <iostream>

using namespace std;

void swap(int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}

void reverse(int arr[], unsigned length)
{
    for (size_t i = 0; i < length / 2; i++)
    {
        swap(arr[i], arr[length - i - 1]);
    }
    
}

int main()
{
    constexpr unsigned MAX_SIZE = 10;
    int arr[MAX_SIZE];

    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        cin >> arr[i];
    }

    reverse(arr, MAX_SIZE);

    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
        
}