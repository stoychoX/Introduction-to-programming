#include <iostream>

unsigned flipNumber(unsigned number)
{
	return (number ^ 2);
}

int main()
{
    std::cout << flipNumber(0) << std::endl;
    std::cout << flipNumber(1) << std::endl;
    std::cout << flipNumber(2) << std::endl;
    std::cout << flipNumber(3) << std::endl;
    std::cout << flipNumber(4) << std::endl;
}