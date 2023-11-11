#include <iostream>

using namespace std;
// 1. Въвеждаме тайното число, което потребителя ще трябва да познае.
// 2. Потребителя въвежда число:
// 2.1 Ако има 4 бика край.
// 2.2 Ако няма 4 бика покажи му колко бика и колко крави има и се върни на 2.

unsigned digitsCount(unsigned number)
{
    if(number == 0) { return 1; }

    unsigned counter = 0;

    while(number != 0)
    {
        ++counter;
        number /= 10;
    }

    return counter;
}

bool containsDigit(unsigned number, unsigned digit)
{
    if(number == 0) { return (digit == 0); }

    while(number != 0)
    {
        if(number % 10 == digit) { return true; }
        number /= 10;
    }
    return false;
}

bool containsDigit(unsigned number, unsigned digit, int& pos)
{
    if(number == 0) 
    {
        pos = (digit == 0) ? 0 : -1;
        return (digit == 0); 
    }
    int posCounter = 0;

    while(number != 0)
    {
        if(number % 10 == digit) 
        { 
            pos = posCounter;
            return true; 
        }
        number /= 10;
        ++posCounter;
    }

    pos = -1;
    return false;
}

bool hasDuplicates(unsigned number)
{
    while(number != 0)
    {
        unsigned lastDigit = number % 10;
        number /= 10;
        if(containsDigit(number, lastDigit)) { return true; }
    }

    return false;
}

bool validNumber(unsigned number)
{
    return digitsCount(number) == 4 && !hasDuplicates(number);
}

unsigned getInput()
{
    unsigned input = 0;
    bool validNumberEntered;

    do
    {
        cout << "Enter number: ";
        cin >> input;
        validNumberEntered = validNumber(input);

        if(!validNumberEntered)
        {
            cout << "This number is invalid. Please try again" << endl;
        }
    } while (!validNumberEntered);
    
    return input;
}

void countBullsAndCows(unsigned& bulls, unsigned& cows, unsigned secret, unsigned guess)
{
    bulls = cows = 0;

    unsigned posCounter = 0;
    int pos = 0;
    while(guess)
    {
        unsigned lastDigit = guess % 10;
        bool contain = containsDigit(secret, lastDigit, pos);

        if(contain)
        {
            if(pos == posCounter)
            {
                ++bulls;
            }
            else
            {
                ++cows;
            }
        }
        ++posCounter;
        guess /= 10;
    }
}

int main()
{
    cout << "Lets make secret number." << endl;
    unsigned secret = getInput();
    cout << "Game starts" << endl;

    bool wonTheGame = false;
    unsigned bulls = 0;
    unsigned cows = 0;

    do
    {
        unsigned guess = getInput();
        countBullsAndCows(bulls, cows, secret, guess);
        wonTheGame = (bulls == 4);
        cout << "Bulls: " << bulls << " Cows: " << cows << endl;        
    } while (!wonTheGame);

    cout << "You won!" << endl;
}