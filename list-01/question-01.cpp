#include <iostream>
/*Problema:  Escreva um programa para somar uma sequência de inteiros e
calcular sua média. Suponha que o primeiro inteiro lido com scanf especifique
o número de valores a serem inseridos. Seu programa deve ler apenas um
valor cada vez que scanf é executado. Uma sequência de entrada típica pode
ser:
7 678 234 315 489 536 456 367
*/
int main()
{
    int quantidade;
    float soma = 0;
    printf("Digite a quantidade de numeros a ser inserido:\n");
    scanf("%d", &quantidade);
    int vetor[quantidade];
    for (int i = 0; i < quantidade; i++)
    {
        printf("Insira o %d° numero:\n", i + 1);
        scanf("%d", &vetor[i]);
    }
    for (int i = 0; i < quantidade; i++)
    {
        soma = soma + vetor[i];
    }
    float media = soma / quantidade;
    printf("A media é: %.1f\n", media);
}