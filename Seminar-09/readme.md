# Девети семинар по увод в програмирането - 27.11.2023

## Побитови операции
В последния семинар разгледахме как се представят целочислените типове и типът char в паметта.
Стандартно типът `int` е 4 байта (1 байт е 8 бита - един бит приема стойности 0 и 1). Давайки различни стойности на 32-та байта с които разполагаме, ние кодираме различни числа в двоична бройна система.

```cpp
int a = 0; // 00000000 00000000 00000000 00000000
int b = 3; // 00000000 00000000 00000000 00000011
int c = 5; // 00000000 00000000 00000000 00000101
```

Побитовите операции ни дават възможност да работим на ниво битове. Предимството на побитовите операции е, че са бързи и доста често можем компактно да пазим информация "скривайки" я в битовете на числото. 

## Bitwise AND (&) - побитово `и`
Ако `A` и `B` са битове, то:
| A | B | A & B |
|---|---|-------|
| 0 | 0 |   0   |
| 0 | 1 |   0   |
| 1 | 0 |   0   |
| 1 | 1 |   1   |

А какво правим когато не работим само с един бит ами с число? Преизползваме логиката за всеки бит на числото!

```
3 & 5 = 
    00000000 00000000 00000000 00000011
&
    00000000 00000000 00000000 00000101
    -----------------------------------
    00000000 00000000 00000000 00000001
```
Най - десния бит е единица понеже най - десния бит на първото число е 1 както и най - десния на второто. Нямаме други единици понеже нямаме други две позиции на които имаме единици.

## Bitwise OR (|) - побитово `или`
Ако `A` и `B` са битове, то:
| A | B | A \| B |
|---|---|--------|
| 0 | 0 |   0    |
| 0 | 1 |   1    |
| 1 | 0 |   1    |
| 1 | 1 |   1    |

Тук логиката е същата като побитово и. За всяка позиция прилагаме операцията.

```
3 | 5 = 
    00000000 00000000 00000000 00000011
|
    00000000 00000000 00000000 00000101
    -----------------------------------
    00000000 00000000 00000000 00000111
```
Най - десните три бита са единици понеже на съответстващите им позиции, прилагайки операцията побитово и, получаваме 1.

## Bitwise XOR (^)
Ако `A` и `B` са битове, то:
| A | B | A ^ B |
|---|---|-------|
| 0 | 0 |   0   |
| 0 | 1 |   1   |
| 1 | 0 |   1   |
| 1 | 1 |   0   |

Отново - аналогична идея:
```
3 ^ 5 = 
    00000000 00000000 00000000 00000011
^
    00000000 00000000 00000000 00000101
    -----------------------------------
    00000000 00000000 00000000 00000110
```
Тук най - десния бит е 0 понеже 1 ^ 1 = 0 в таблицата.

Какво се случва когато направим a ^ a?
## Bitwise NOT (~)
За разлика от предните оператори - този е унарен. Приема едно число и просто обръща битовете му:
Ако `A` е бит, то:
| A | ~A |
|---|----|
| 0 |  1 |
| 1 |  0 |

Пример:
```
~5 = ~00000000 00000000 00000000 00000101
   =  11111111 11111111 11111111 11111010
   = -6
```

Представяйки числата в 2s complement, ако `a` е число можем да получим `-a` по следния начин:
```cpp
int a = 5;
int b = ~a + 1; // Обърни битовете на а и добави 1
```

## Bitwise shifting (<<, >>) - побитово отместване.
Нека разгледаме дясно побитово отместване >>. То приема число и брой битове които ще "отместим".

Интуитивно отместването е все едно "придърпваме" битовете на числото надясно (или наляво).

Получава се нещо такова за дясно отместване:

![](https://cdn.getmidnight.com/84f7b02a8128f5f5775611244c24b941/2021/02/ezgif.com-gif-maker--2--1.gif)

И нещо такова за ляво:

![](https://cdn.getmidnight.com/84f7b02a8128f5f5775611244c24b941/2021/02/ezgif.com-gif-maker--1-.gif)

Разбира се, битовете не са усмихнати, нито цветни. Нека разгледаме по - подробно примера:

```cpp
// В началото числото е 0100 1101. Последователно падат 4 бита от дясната страна. 
#include <iostream>

int main()
{
    int a = 77; // 01001101
    a = a >> 1; // Пада 1 бит
    a = a >> 1; // Пада 1 бит
    a = a >> 1; // Пада 1 бит
    a = a >> 1; // Пада 1 бит
    // Паднаха 4 бита
    std::cout << a << std::endl; // Това трябва да е точно числото 0000 0100 което е 4.

    // За да не шифтваме 4 пъти (моля ви не го правете) можем просто да напишем
    int b = 77;
    b = b >> 4; // отмества 4 бита
    std::cout << b; // Отново 4
}
```
Лявото отместване е аналогично - този път обаче битовете "падат" от другата страна.
```cpp
#include<iostream>

int main()
{
    int a = 16; // 0001 0000
    a = a << 1; // 0010 0000
    a++;        // 0010 0001
    a = a << ;  // 0100 0010
}
```

Какво ще изведе следния код:

```cpp
#include<iostream>

int main()
{
    std::cout << (-1 >> 1);
}
```
Извежда -1. Както видяхме:
```
-1 = 11111111 11111111 11111111 11111111 // обърнете битовете и добавете 1. Колко получавате?
```
След като отместим един път надясно продължаваме да имаме същата стойност. Това е понеже дясното отместване в С++ запазва бита за знака. Има вариация на дясното отместване, която не го запазва. 

## Примери
* Проверка за четност на число.
* Бърза степен на двойката.
* Проверка дали число е степен на двойката.

## Статични двумерни масиви. Матрици.
Когато разглеждахме масивите видяхме, че можем да имаме масиви от различни типове. Можем да имаме масиви от тип `int` а можем и да имаме масиви от тип `char`. А възможно ли е да имаме масиви от масиви?
Да и точно това представляват двумерните масиви.
```cpp
#include <iostream>

int main()
{
    int matrix[3][3]; // Масив от три масива

    int initializedMatrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    }; // Това е валиден синтаксис

    int arr[][]; // това е невалиден синтаксис. Трябва да подадем измеренията на масива.
}
```
Можем ли да имаме масив от масиви от масиви? Разбирасе, че можем. Можем да продължаваме логиката колкото искаме (или колкото памет имаме), но ще се ограничим до двумерни масиви (още наричани матрици).

## Задачи за самостоятелна подготовка
Да се реализира функция ```void printAllSubsets(int arr[], size_t size)``` която принтира всички подмножества на множество представено чрез масив.

Пример:

arr = {1, 2}

size = 2

Изход:

{}
{1}
{2}
{1, 2}

Hint: Всяко подмножество може да се представи чрез битвектор, 1 означава, че елементът се включва а 0, че не се. Обхождайки всички битвектори, представящи подмножества (тези с дължина size) всеки от тях ще Ви представлява точно едно подмножество. 

Елементите на масива не са повече от 32. 