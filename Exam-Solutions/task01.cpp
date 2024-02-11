#include <iostream>
 
unsigned countDigitOccurences(unsigned n, int digit)
{
    if(n == 0 && digit == 0)
        return 1;
 
    unsigned count = 0;
    while(n != 0)
    {
        if(n % 10 == digit)
            count++;
        n /= 10;
    }
    return count;
}
bool infixOfPermutation(unsigned N, unsigned K)
{
    for(int i = 0; i <= 9; i++)
        if(countDigitOccurences(N, i) < countDigitOccurences(K, i))
            return false;
    return true;
}

int main() 
{
    unsigned first = 12364;
    unsigned second = 30;
    std::cout << infixOfPermutation(first, second);
}