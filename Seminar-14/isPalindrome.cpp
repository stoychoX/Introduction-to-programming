#include <iostream>
#include <cstring>

bool isPalindromeRec(const char* text, size_t len)
{
    if(len < 2)
    {
        return true;
    }
    if(text[0] != text[len - 1])
    {
        return false;
    }

    return isPalindromeRec(text + 1, len - 2); 
}

bool isPalindrome(const char* text)
{
    return isPalindromeRec(text, strlen(text));
}

int main()
{
    std::cout << isPalindrome("abc???cba") << std::endl;
    std::cout << isPalindrome("abc??1>?cba");
}