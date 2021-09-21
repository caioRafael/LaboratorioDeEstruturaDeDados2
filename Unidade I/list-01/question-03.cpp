#include <iostream>
/*
Escreva um programa para calcular e imprimir a soma de todos
os múltiplos de 7 partindo de 1 até 100.
*/
int main()
{

    int quantidade_multiplos = 0, resto, soma = 0;
    printf("Todos os multiplos de 7 de 1 a 100:\n[ ");
    for (int i = 1; i <= 100; i++)
    {
        resto = i % 7;
        if (resto == 0)
        {
            quantidade_multiplos++;
            soma = soma + i;
            printf("%d ", i);
        }
    }
    printf("]\nQuantidade de multiplos: %d\n", quantidade_multiplos);
    printf("SOMA = %d\n", soma);
}