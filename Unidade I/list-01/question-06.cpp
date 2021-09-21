#include <iostream>
/*
A função fatorial é freqüentemente usada em problemas de
probabilidade. O fatorial é igual ao produto dos inteiros positivos de 1 a n.
Escreva um programa que avalie os fatoriais dos inteiros de 1 a n. Imprima
os resultados em formato tabular.
*/
int fatorar(int numero)
{
    if (numero == 0)
    {
        return 1;
    }
    else
    {
        return numero * fatorar(numero - 1);
    }
}
int main()
{
    int numero;
    printf("Digite um numero:\n");
    scanf("%d", &numero);
    int vetor[numero];
    for (int i = 1; i <= numero; i++)
    {
        vetor[i] = fatorar(i);
    }
    printf("NUMERO\t||\tFATORADO\n");
    for (int i = 1; i <= numero; i++)
    {
        printf("%d\t\tfat(%d) = %d\n", i, i, vetor[i]);
    }
}