// Problema 19 Escreva dois programas que recebem como parâmetro três
// inteiros representando os coeficientes de uma função do segundo grau e execute:
// a) O teste para saber se essa função tem raízes reais;
// b) O valor das raízes reais.
// How to run: 
// gcc question-19.cpp -o question-19
// ./question-19 

#include <stdio.h>
#include <math.h>

void secondDegree(float a, float b, float c){
  float delta, x1, x2;
  delta = (b*b)-(4*a*c);
  if (delta < 0) {
    printf("Não há raízes reais\n");
  } else {
    delta = sqrt(delta);
    x1 = (-b+delta)/(2*a);
    x2 = (-b-delta)/(2*a);
    printf("x1 = %.2f\nx2 = %.2f\n", x1, x2);

  }
}

int main() {
 float a, b, c;
 printf("Insira os coeficientes da equação: ");
 scanf("%f %f %f", &a, &b, &c);
 
 secondDegree(a, b, c);  
}