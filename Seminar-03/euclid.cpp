#include <iostream>

using namespace std;

int main()
{
    unsigned first  = 0;
    unsigned second = 0;

    cin >> first >> second;

    if(first < second)
    {
        unsigned temp = first;
        first = second;
        second = temp;
    }

    while(second != 0)
    {
        unsigned firstTemp = first;
        first = second;
        second = firstTemp % second;
    }

    cout << first;
}