#include<iostream>

using namespace std;

unsigned gcd(unsigned a, unsigned b)
{
    if(b > a)
    {
        unsigned temp = a;
        a = b;
        b = temp;
    }

    while(b != 0)
    {
        unsigned temp = a;
        a = b;
        b = temp % a;
    }

    return a;
}

void firstProblem()
{
    unsigned numerator = 0;
    unsigned denominator = 0;

    cin >> numerator >> denominator;
    unsigned greatestCommonDivisor = gcd(numerator, denominator);

    cout << numerator / greatestCommonDivisor << " " << denominator / greatestCommonDivisor << endl;
}

void secondProblem()
{
    unsigned numeratorFirst = 0;
    unsigned denominatorFirst = 0;
    unsigned numeratorSecond = 0;
    unsigned denominatorSecond = 0;
    cin >> numeratorFirst >> denominatorFirst >> numeratorSecond >> denominatorSecond;

    // Знаменателя ще е lcm на знаменателите. Него намираме чрез gcd.
    unsigned greatestCommonDivisor = gcd(denominatorFirst, denominatorSecond);

    unsigned resultDenominator     = (denominatorFirst / greatestCommonDivisor) * denominatorSecond;
    unsigned resultNumerator = (numeratorFirst * (resultDenominator / denominatorFirst)) + (numeratorSecond * (resultDenominator / denominatorSecond));

    // Трябва да съкратим резултата, понеже нямаме гаранция, че винаги
    // ще е съкратена дроб.
    unsigned gcdResult = gcd(resultNumerator, resultDenominator);
    cout << resultNumerator / gcdResult << " " << resultDenominator / gcdResult << endl;
}

bool validTimestamp(unsigned x)
{
    return x < 2400 && x % 100 < 60;
}

void thirdProblem()
{
    unsigned timestampOne = 0;
    unsigned timestampTwo = 0;

    cin >> timestampOne >> timestampTwo;

    if(!validTimestamp(timestampOne))
    {
        cout << "Invalid timestamp: " << timestampOne << endl;
        return;
    }

    if(!validTimestamp(timestampTwo))
    {
        cout << "Invalid timestamp: " << timestampTwo << endl;
        return;
    }
    if(timestampOne < timestampTwo)
    {
        unsigned temp = timestampOne;
        timestampOne  = timestampTwo;
        timestampTwo  = temp;
    }

    int resultHours = (timestampOne / 100) - (timestampTwo / 100);
    int resultMins  = (timestampOne % 100) - (timestampTwo % 100);

    if(resultMins < 0)
    {
        resultMins += 60;
        --resultHours;
    }

    cout <<"Difference: " << resultHours << " hours and " << resultMins << " minutes." << endl;
}

int main()
{

}