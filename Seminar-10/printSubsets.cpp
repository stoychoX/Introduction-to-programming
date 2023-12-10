#include <iostream>

// Провери дали битът на позиция elementPos e вдигнат в currentSubset
bool elementContainedInCurrentSubset(unsigned currentSubset, unsigned elementPos)
{
    return ((currentSubset & (1 << elementPos)) != 0);
}

void printSubset(const int set[], unsigned size, unsigned currentSubset)
{
    std::cout << "{ ";
    for (size_t i = 0; i < size; i++)
    {
        if(elementContainedInCurrentSubset(currentSubset, i))
        {
            std::cout << set[i] << " ";
        }
    }
    std::cout << "}" << std::endl;
}

// Защо това работи?
// Броя на всички подмножества на множество с n eлемента е 2^n.

// Бележка: В множествата елементите не са наредени. Все пак в случая представяме множеството като масив,
// и за да улесним разбирането на задачата можем да говорим за "елемент на позиция i".

// Подмножество можем да представим като последователност от нули и единици - ако имаме единица на позиция i
// то елементът на позиция i се среща в подмножеството. В противен случай не се среща.

// Примерно:
// {1, 2, 3, 4, 5}
//  0  1  1  0  1
// това представлява подмножеството {2, 3, 5}.

// Обхождайки всяка такава последователност от нули и единици ни води до всички подмножества.
// Това обхождане правим като обхождаме числата от 0 до 2^size.
// За всяко число - ако битът на позиция i e вдигнат изведи елемента в противен случай недей.
void printSubsets(const int set[], unsigned size)
{
    size_t subsetsCount = (1 << size); // Бързо 2^size.
    for (size_t currentSubset = 0; currentSubset < subsetsCount; currentSubset++)
    {
        printSubset(set, size, currentSubset);
    }
}

int main()
{
    constexpr unsigned SET_SIZE = 5;
    int set[SET_SIZE] = {1, 2, 3, 4, 5};
    printSubsets(set, SET_SIZE);
}