#include <iostream>
#include <string.h>

using namespace std;

int sumDigits(int number);
int main()
{

  int sum = sumDigits(7631);

  printf("%d \n", sum);

  return 0;
}

int sumDigits(int number)
{
  int sum = 0;

  while (number != 0)
  {
    sum += number % 10;
    number = number / 10;
  }

  return sum;
}
