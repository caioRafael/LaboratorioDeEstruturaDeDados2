#include <iostream>
/*
 Uma aplicação interessante de computadores é desenhar gráficos e gráficos de barras.
  Escreva um programa que leia cinco números (cada
um entre 1 e 30). Para cada número lido, seu programa deve imprimir uma
linha contendo aquele número de asteriscos adjacentes. Por exemplo, se seu
programa lê o número sete, ele deve imprimir ∗ ∗ ∗ ∗ ∗ ∗ ∗
*/
int main()
{
    int x = 0, y;
    int numero;
    while (x < 5)
    {
        y = 0;
        printf("Digite o %d° numero entre 1 e 30\n", x + 1);
        scanf("%d", &numero);
        while (numero > 30 || numero < 1)
        {
            printf("Numero não atende aos criterios exigidos.\n");
            printf("Digite o %d° numero entre 1 e 30\n", x + 1);
            scanf("%d", &numero);
        }
        while (y < numero)
        {
            printf("*");
            y++;
        }
        printf("\n");

        x++;
    }
}