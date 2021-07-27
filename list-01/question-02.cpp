#include <iostream>
/*
Escreva um programa que converta temperaturas de 30°C a
50°C para a escala Fahrenheit espaçados de 1°C. O programa deve imprimir
uma tabela exibindo as temperaturas nas duas escalas lado a lado. [Dica:
F = C + 32]
*/
typedef struct GRAUS
{
    int celsius;
    float fahreheit;
} Graus;

int main()
{
    int maior_grau = 50, menor_grau = 30;
    int total_tabela = maior_grau - menor_grau;
    Graus g[total_tabela + 1]; //+1 pra poder contar com o ultimo grau = 50, ja que vai de 0 a 19
    int inicio = menor_grau;
    for (int i = 0; i <= total_tabela; i++)
    {

        g[i].celsius = inicio;
        g[i].fahreheit = inicio * 1.8 + 32; //1.8 é constante
        inicio++;
    }
    printf("CELSIUS\t   ||\tFAHREHEIT\n");
    for (int i = 0; i <= total_tabela; i++)
    {
        printf("%d°C\t\t%.1f°F\n", g[i].celsius, g[i].fahreheit);
    }
}
