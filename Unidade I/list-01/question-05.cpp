#include <iostream>
/*
Escreva um programa que imprima a soma, a soma dos quadrados e a 
soma dos cubos de todos os números naturais de 1 até qualquer
número inserido pelo usuário
*/
int main()
{
    int cubo, quadrado;
    int soma_cubo = 0, soma_quadrado = 0, soma_inteiro = 0;
    printf("TODOS OS INTEIROS DE 1 A 100:\n");

    for (int i = 1; i <= 100; i++)
    {
        printf("%d ", i);
        soma_inteiro = soma_inteiro + i;
    }
    printf("\nCUBOS DE 1 A 100:\n");
    for (int i = 1; i <= 100; i++)
    {
        cubo = i * i * i;
        if (cubo <= 100)
        {
            printf("%d\n", cubo);
            soma_cubo = soma_cubo + cubo;
        }
    }
    printf("QUADRADOS DE 1 A 100:\n");
    for (int i = 1; i <= 100; i++)
    {
        quadrado = i * i;

        if (quadrado <= 100)
        {
            printf("%d\n", quadrado);
            soma_quadrado = soma_quadrado + quadrado;
        }
    }
    printf("-------------------------------------------\n");
    printf("SOMA DOS INTEIROS:%d\nSOMA CUBOS:%d\nSOMA QUADRADOS:%d\n", soma_inteiro, soma_cubo, soma_quadrado);
}