#include <iostream>

int main()
{
    int variable = 14;
    std::cout << "The address of variable is: " << &variable << std::endl;
    int *variablePtr = &variable;

    std::cout << "Variable pointer address is: " << variablePtr << std::endl;
    std::cout << "Variable value: " << variable << " variable ptr value: " << *variablePtr << std::endl;
    std::cout << "Changing the variable ptr value to 10..." << std::endl;
    *variablePtr = 10;
    std::cout << "Variable value: " << variable << " variable ptr value: " << *variablePtr << std::endl;
}