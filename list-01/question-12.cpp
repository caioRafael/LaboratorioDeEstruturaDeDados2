// Problema 12 Escreva um programa que imprima uma tabela de todos os
// equivalentes de algarismos romanos dos números decimais no intervalo de 1
// a 100.

#include <stdio.h>
#include <string.h>

void getRomaNum(int num){
  char NUMERATIONSROMAN[7][2] = {"I", "V", "X", "L", "C", "D", "M"};
  int NUMERATIONSDECIMAL[7] = {1, 5, 10, 50, 100, 500, 1000};

  char romanStr[20];
 
  while (num > 0)
  {
    if (num >= 1 && num <= 3) {
      strcat(romanStr, "I");
      num = num - 1;
    } else if (num == 4) {
      strcat(romanStr, "IV");
      num = num - 4;
    }
    else if (num >=5 && num < 10){
      strcat(romanStr, "V");
      num = num - 5;
    } else if ( num >= 10 && num <= 50){
      strcat(romanStr, "X");
      num = num - 10;
    } else if ( num >= 50 && num < 100){
      strcat(romanStr, "L");
      num = num - 50;
    } else if (num >= 100 && num < 500){
      strcat(romanStr, "C");
      num = num - 100;
    } else if (num >= 500 && num < 1000) {
      strcat(romanStr, "D");
      num = num - 500;
    }
  }

  printf("%s\n", romanStr);
}

int main(){
  for (int i = 0; i < 100; i++)
  { 
     printf("%d\n", i);
     getRomaNum(i);
  }
  
}