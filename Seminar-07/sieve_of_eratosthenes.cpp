#include <iostream>
#include <cmath>

using namespace std;

void initSieve(bool sieve[], unsigned length, bool value)
{
    for (unsigned i = 0; i < length; i++)
    {
        sieve[i] = value;
    }
}

void mark(bool sieve[], unsigned length, unsigned from)
{
    unsigned step = from;
    unsigned cell = 2 * from;

    while(cell <= length)
    {
        sieve[cell] = false;
        cell += from;
    }
}

void preprocessSieve(bool sieve[], unsigned length)
{
    sieve[0] = sieve[1] = false;

    unsigned border = sqrt(length) + 1;

    for (unsigned i = 2; i <= border; i++)
    {
        if(sieve[i])
        {
            mark(sieve, length, i);
        }
    }
}

void handleQuery(bool sieve[], unsigned length)
{
    int input = 0;
    
    while(input >= 0)
    {
        cin >> input;

        if(input > length)
        {
            cout << "Invalid number" << endl;
        }
        else if(input < 0)
        {
            cout << "Goodbye" << endl;
        }
        else if(sieve[input])
        {
            cout << "Number is prime" << endl;
        }
        else
        {
            cout << "Number is not prime" << endl;
        }
    }
}

int main()
{
    constexpr unsigned SIEVE_MAX_LEN = 1024 + 1;
    bool sieve[SIEVE_MAX_LEN];
    initSieve(sieve, SIEVE_MAX_LEN, true);
    preprocessSieve(sieve, SIEVE_MAX_LEN);
    handleQuery(sieve, SIEVE_MAX_LEN);
}