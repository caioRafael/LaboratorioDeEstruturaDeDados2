#include <iostream>
/*
 Escreva a função anterior e passe como parâmetro o caractere
que deseja imprimir.
Questao anterior: Escreva uma função que exibe um retângulo sólido de asteriscos cujos lados são especificados nos parâmetros inteiros lado1 e lado2. Por
exemplo, se os lados são 4 e 5, a função exibe o seguinte:
∗ ∗ ∗ ∗ ∗
∗ ∗ ∗ ∗ ∗
∗ ∗ ∗ ∗ ∗
∗ ∗ ∗ ∗ ∗
*/
void preencher_mostrar(char **matriz, int lado1, int lado2, char caractere)
{
    for (int i = 0; i < lado1; i++)
    {
        for (int j = 0; j < lado2; j++)
        {
            matriz[i][j] = caractere;
        }
    }
    printf("Mostrando matriz ...\n");
    for (int i = 0; i < lado1; i++)
    {
        for (int j = 0; j < lado2; j++)
        {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}
char **alocar(int lado1, int lado2)
{
    char **mat = NULL;
    mat = (char **)malloc(lado1 * sizeof(char *));

    if (mat != NULL)
    {
        for (int i = 0; i < lado2; i++)
        {
            mat[i] = (char *)malloc(lado2 * sizeof(char));
        }
    }
    return mat;
}
int main()
{
    int lado1, lado2;
    char caractere;
    char **matriz = NULL;
    printf("Digite um caractere:\n");
    scanf("%c", &caractere);
    printf("Digite numero de linhas e numero de colunas\n");
    scanf("%d %d", &lado1, &lado2);
    matriz = alocar(lado1, lado2);
    preencher_mostrar(matriz, lado1, lado2, caractere);
}