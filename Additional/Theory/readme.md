# Въпрос 1
Да се напише оператор за цикъл for, който отпечатва същите числа като следния оператор: for (int i = 0; i < 2 * count + 1; i += 2) cout << i;, но в ОБРАТЕН РЕД

```cpp
for (int i = 2 * count; i >= 0; i -= 2)
{
    std::cout << i;
}
```
# Въпрос 2
Какво ще се отпечата при изпълнението на следния код?
```cpp
dоuble d = 1.25; int i = d + 1.25; i += 0.5;
cоut << i;
```

**Отговор**: 2

# Въпрос 3
Какво ще отпечата следният код?
```cpp
for (int i = 1; i <= 4; i++) {
  if (i == 2) {
    continue;
  }
  if (i == 4) {
    break;
  }
  for (int j = 1; j <= 3; j++) {
    if (j == 2) {
      break;
    }
    cout << i << j;
  }
}
```

**Отговор**: 1131

# Въпрос 4
Какво ще се отпечата при изпълнението на следния код?
```cpp
int global = 1;

void f(int a, int *b, int &c) {
  a += 4 * global;
  *b += 2 * global;
  c += global;
}

int main() {
  f(global, &global, global);
  cout << global << endl;
  return 0;
}
```

**Отговор**: 6

# Въпрос 5
Какво ще се отпечата при извикване на f(4)?
```cpp
void f(int x) {
  if (x % 2 == 0) {
    x /= 2;
    f(x);
  }
  cout << x;
}
```

**Отговор**: 112

# Въпрос 6
Колко байта заема в паметта следният символен низ? char s[] = "BNN\nB\nB\n";

**Отговор**: 9

# Въпрос 7
Обяснете защо не трябва функция да връща указател към нейна локална променлива

**Отговор**: Локалните променливи се трият след приключване на функцията. Върнатия указател ще сочи към невалиден адрес.

# Въпрос 8
Нека оператор 1 е "&&", оператор 2 е "||", оператор 3 е "!", а оператор 4 е двуаргументният "+". Подредете операторите по приоритет в намаляващ ред (в полето за отговор напишете 4-цифреното число, образувано от техните номера, напр. 1234).

**Отговор**: 3412

# Въпрос 9
Кой от двата цикъла извежда правилно дължината на символния низ?
```cpp
int main() {
 char text[] = "statistics";

 int index = 0;

 for (; text[index]; ++index);
 cout << index;

 index = 0;

 while (text[index]);
 cout << index;

 return 0; 
}
```

**Отговор**: for цикъла

# Въпрос 10
Имаме следната функция: vоid f(int a) { f(а); а--; }. Какво не е наред?

**Отговор**: Това е безкрайна рекурсия.

# Въпрос 11
Да разгледаме програмен фрагмент: int variable = 15;. Какво е "15"?

**Отговор**: целочислен литерал.

# Въпрос 12
Кое от следните твърдения НЕ е вярно?

1. a = (x > 0 ? c : 0); е еквивалентно на a = c; if (x <= 0) a -= a;

2. (x == 0 ? b : c) е еквивалентно на (x ? c : b), където x е израз от тип int

3. A && B е еквивалентно на A ? true : B

4. a = (x > 5 ? c : d); е еквивалентно на a = c; if (x <= 5) a = d;

**Отговор**: 3

# Въпрос 13
В кой от следните програмни фрагменти има грешка при работата с масиви?


1. Всички фрагменти са коректни

2.  
```cpp
long numbers[] = {4, 3};
for (int i = 0; i <= 2; i++) numbers[i % 2]++;
```

3.  
```cpp
long numbers[6] = {4, 9, 0};
```

4.  
```cpp
long a,b[10];
a[4] = 0;
b[7] = 8;
```
**Отговор**: 4

# Въпрос 14
Кое от следните твърдения НЕ е вярно в C++?

1. На delete НЕ може да бъде подаден адрес в стековата памет

2. Динамична памет може да бъде заделена и освободена по всяко време на изпълнение на програмата

3. При извикване на функция се създава нова стекова рамка. При приключването на изпълнението й тази памет се освобождава

4. Памет, заделена с оператор new, се освобождава автоматично, когато не е необходима

**Отговор**: 4

# Въпрос 15
Кое от следните твърдения НЕ е вярно?

1. В следния код:
```cpp
if (a == 0) X; else if (b == 1 && a != 0) Y;
```
има излишна проверка

2. if (P) A; е еквивалентно на if (!P) {} else A;

3. В тялото на оператор if можем да напишем for цикъл

4. if (number++ == 1) something(); else if (number++ == 2) somethingElse(); е еквивалентно на същия код, но без else

**Отговор**: 4

# Въпрос 16
Кое от следните твърдения за многомерните масиви е вярно?

1. double f[2, 3] е двумерен масив с общо 6 елемента

2. Многомерните масиви се представят в паметта като едномерни и можем да декларираме например 10-мерен масив

3. Следната декларация е коректна: unsigned int m[][7];

4. При многомерните масиви елементите в различните измерения могат да бъдат от различен тип (напр. int и double)

**Отговор**: 2

# Въпрос 17
Кое от следните твърдения за функции в C++ НЕ е вярно?

1. Името на една функция не може да започва с цифра

2. Ако дефинираме подходящи функции, големите програми могат да бъдат лесно четими

3. Една функция може да извиква други функции и дори себе си

4. Ако дадена функция няма параметри, при извикването й не е необходимо да поставяме кръгли скоби след името й

**Отговор**: 4

# Въпрос 18
Нека array е масив от тип double с 6 елемента, а i e int. Кое от следните твърдения е вярно?

1. &array[0] е еквивалентно на !array

2. array[i] е еквивалентно на *(i + array)

3. array[4] - array[3] има стойност sizeof(double)

4. &array[i] е еквивалентно на array[*i]

**Отговор**: 2

# Въпрос 19
В кой от следните примери има неявно преобразуване на тип?

1. long a, b; cin >> a; b = a;

2. double d = 4.7; return (int)d;

3. int b = 4 > 5;

4. cout << (char)65;

**Отговор**: 3

# Въпрос 20
Кое от следните твърдения за структурите в C++ е вярно?

1. Полетата на една структура трябва да бъдат от различен тип

2. Ако имаме структура Fraction и функция f(Fraction ratio), функцията ще получи копие на подадената й стойност

3. Нека имаме структура struct Timе { int hours, minutеs; }; и функция vоid midnight(Time time) { timе.hours = time.minutes = 0; }. Следният код ще отпечата 0: Time t = {9, 25}; midnight(t); cout << t.hours;

4. Ако p е указател към запис, а f е поле на този запис, то p->f е еквивалентно на *(p.f)

**Отговор**: 2

# Въпрос 21
Кое от следните твърдения е вярно?

1. Компонентите на for(инициализация; условие; корекция) тяло се изпълняват в следния ред: инициализация, условие, корекция, тяло, условие, корекция, тяло и т.н.

2. Условието в един for цикъл се проверява преди всяка итерация и ако не е вярно, тялото не се изпълнява

3. За разлика от do-while, при while тялото се изпълнява най-малко един път

4. Тялото на един for цикъл не може да съдържа други оператори for

**Отговор**: 2

# Въпрос 22
Кое от следните твърдения е вярно за C++?


1. Глобалните променливи се декларират в глобални функции и са достъпни и извън тях

2. Променливи, декларирани в тялото на do-while цикъл, могат да бъдат използвани в условието в while

3. int fact; for (int i = 1; i <= 6; i++) fact *= i; пресмята коректно факториел от 6

4. В рамките на един блок не можем да имаме променливи с еднакви имена, но в различни блокове - можем, дори и единият блок да е вложен в другия

**Отговор**: 4

# Въпрос 23
Кое от следните твърдения е вярно?

1. За да отпечатаме стойностите на масив int a[10], използваме cout << a;

2. Масив с 8 елемента от тип bool заема един байт памет

3. При дефиниране на едномерен масив може да не указваме броя елементи, стига да сме задали начални стойности за елементите на масива

4. Елементите на масива int a[10] могат да бъдат от произволен числов тип (double, long и т.н.), стига да съдържат най-много 10 цифри

**Отговор**: 3

# Въпрос 24
Кое от следните твърдения е вярно?

1. Ако на даден указател не укажем явно стойност, то той автоматично получава стойност NULL

2. Следният програмен фрагмент е синтактично коректен: int* a, A; a = &A; A = *a = !14;

3. С float* p1, p2; декларираме два указателя от тип float

4. int a = 4; int *p = &a; a++; cout << p; отпечатва сочената от p стойност, а именно 5

**Отговор**: 2

# Въпрос 25
Кой от следните фрагменти НЕ е еквивалентен на следния оператор:
```cpp
switch (number) {
  case 1:
  case 2: сout << 3;
  default: cout << 4;
}
```

1.
```cpp
switch (number) {
  default: cout << 4; break;
  casе 1:
  casе 2: сout << 3; cout << 4;
}
```

2.
```cpp
switсh (number) {
  case 1:
  case 2: сout << 3; cout << 4; break;
  default: cout << 4; brеak;
}
```
3.
```cpp
switch (number) {
  case 1:
  case 2: сout << 3; break;
  default: cout << 4; break;
}
```

4.
```cpp
switch (number) {
  case 1: cout << 34; breаk;
  case 2: сout << 34; brеak;
  default: cout << 4; break;
}
```

**Отговор**: 3

# Въпрос 26
Възможно ли е `main` да е рекурсивна функция?

**Отговор**: да

# Въпрос 27
Какво ще отпечата следния код?
```cpp
#include <iostream>

int mystery(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1 + mystery(n - 1);
  return 2 * mystery(n / 2);
}

int main() {
  std::cout << mystery(17);
}
```

**Отговор**: 17