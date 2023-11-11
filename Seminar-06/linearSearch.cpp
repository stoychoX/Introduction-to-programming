#include <iostream>
using namespace std;

void printArray(const int arr[], unsigned length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}

unsigned linearSearch(const int arr[], unsigned length, int element)
{
    for (size_t i = 0; i < length; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    constexpr unsigned MAX_LEN = 10;
    int arr[MAX_LEN];

    for (size_t i = 0; i < MAX_LEN; i++)
    {
        arr[i] = i;
    }
    
    printArray(arr, MAX_LEN);
    unsigned target = 0;

    cin >> target;

    int pos = linearSearch(arr, MAX_LEN, target);

    if(pos != -1)
    {
        cout << "Element found at position: " << pos << endl;
    }
    else
    {
        cout << "No such element found." << endl;
    }
}