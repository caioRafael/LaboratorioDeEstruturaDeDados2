#include <iostream>

int isPerfect(int *number);
int main(void)
{

  int *number = (int *)malloc(sizeof(int));
  *number = 1;
  while (*number <= 1000)
  {
    if (isPerfect(number))
      printf("%d é perfeito\n\n", *number);

    *number += 1;
  }

  return 0;
}

int isPerfect(int *number)
{
  int sum = 0;

  for (int i = 1; i < *number; ++i)
    if (*number % i == 0)
      sum += i;

  if (sum == *number && *number > 0)
    return 1;
  else
    return 0;
}