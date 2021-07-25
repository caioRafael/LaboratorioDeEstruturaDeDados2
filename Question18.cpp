#include <iostream>

int isPerfect(int *number);
int main(void)
{

  int *number;

  setlocale(LC_ALL, "Portuguese");

  number = (int *)malloc(sizeof(int));

  printf("\nDigite um número natural: ");
  scanf("%d", number);

  if (isPerfect(number))
    printf("%d é perfeito\n\n", *number);
  else
    printf("%d não é perfeito\n\n", *number);

  return 0;
}

int isPerfect(int *number)
{

  size_t i; /* Boa prática para laços: usar size_t */
  int sum;

  sum = 0;

  for (i = 1; i < (size_t)*number; ++i)
    if (*number % i == 0)
      sum += i;

  if (sum == *number && *number > 0)
    return 1; /* É perfeito */
  else
    return 0; /* Não é perfeito */
}