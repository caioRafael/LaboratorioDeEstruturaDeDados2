#include <stdio.h>
#define TAMANHO 8
typedef struct
{
    int chave;
} HASH;
HASH hash[TAMANHO];

void inicializa_hash()
{

    for (int i = 0; i < TAMANHO; i++)
    {
        hash[i].chave = -1;
    }
}
int hash_divisao(int chave)
{
    return chave % TAMANHO;
}
int hash_dobra(int chave)
{
    int total_digitos_bin = 10;
    int p1 = chave >> total_digitos_bin;
    int p2 = chave & (TAMANHO - 1);
    return (p1 ^ p2);
}
int hash_multi(int chave)
{
}
HASH preencher()
{
    HASH h;
    printf("Digite uma chave:\n");
    scanf("%d", &h.chave);
    return h;
}
void inserir(int metodo)
{
    HASH h = preencher();
    int resto;
    if (metodo == 1)
    {
        resto = hash_dobra(h.chave);
    }
    else if (metodo == 2)
    {
        //nada
    }
    else if (metodo == 3)
    {
        resto = hash_divisao(h.chave);
    }
    if (hash[resto].chave == -1)
    {
        hash[resto].chave = h.chave;
    }
}
void mostrar()
{
    printf("---------TABELA HASH-------------\n");
    for (int i = 0; i < TAMANHO; i++)
    {
        if (hash[i].chave != -1)
        {
            printf("pos: %d\tchave: %d\n", i, hash[i].chave);
        }
        else
        {
            //imprime a posição mesmo n tendo nada
            printf("pos: %d\n", i);
        }
    }
}
void menu()
{
    printf("Tamanho do vetor: %d\n\n", TAMANHO);
    printf("1 - Funcao dobra\n");
    printf("2 - Funcao Multiplicacao\n");
    printf("3 - funcao divisao\n");
    printf("0 - SAIR\n");
}
void analisa(int opc)
{
    int continuar;
    do
    {
        inserir(opc);
        printf("1 - Adicionar outro\n0 - SAIR\n");
        scanf("%d", &continuar);
        while (continuar != 1 && continuar != 0)
        {
            printf("ERRO! Digite novamente:\n");
            printf("1 - Adicionar outro\n0 - SAIR\n");
            scanf("%d", &continuar);
        }

    } while (continuar == 1);
}
int main()
{
    int opc;

    inicializa_hash();
    menu();
    scanf("%d", &opc);
    if (opc == 1)
    {
        analisa(opc);
        mostrar();
    }
    else if (opc == 2)
    {
        analisa(opc);
        mostrar();
    }
    else if (opc == 3)
    {
        analisa(opc);
        mostrar();
    }
    else
    {
        system("clear");
        printf("vc saiu...\n");
    }
    printf("\n");
}