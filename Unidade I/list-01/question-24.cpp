#include <iostream>
/*
Somatório de valores de 1 até N.
*/
int main()
{
    int soma = 0, n;
    printf("Digite um valor para N:\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        soma = soma + i;
    }
    printf("RESULTADO DA SOMA: %d\n", soma);
}