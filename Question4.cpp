#include <iostream>

int main()
{
  int numbers[100];

  for (int i = 0; i < 100; i++)
  {
    numbers[i] = i + 1;
  }

  for (int i = 1; i < 101; i++)
  {
    if (!((
              ((numbers[i] % 2 == 0) and (numbers[i] != 2)) or
              ((numbers[i] % 3 == 0) and (numbers[i] != 3))) or
          (((numbers[i] % 5 == 0) and (numbers[i] != 5)) or
           ((numbers[i] % 7 == 0) and (numbers[i] != 7)))))
    {
      printf("%d\n", numbers[i]);
    }
  }

  return 0;
}
