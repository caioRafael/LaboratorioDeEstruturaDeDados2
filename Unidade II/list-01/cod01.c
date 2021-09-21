#include <stdio.h>
typedef struct
{
    int chave;
} HASH;
HASH hash[8];
void inicializa_hash()
{

    for (int i = 0; i < 8; i++)
    {
        hash[i].chave = -1;
    }
}
int resto_divisao(int chave)
{
    return chave % 8;
}
HASH inserir()
{
    HASH h;
    printf("Digite uma chave:\n");
    scanf("%d", &h.chave);
    return h;
}
void inserir_divisao()
{
    HASH h = inserir();
    int resto = resto_divisao(h.chave);
    if (hash[resto].chave == -1)
    {
        hash[resto].chave = h.chave;
    }
}
void mostrar()
{
    printf("---------\n");
    for (int i = 0; i < 8; i++)
    {
        if (hash[i].chave != -1)
        {
            printf("pos: %d\tchave:%d\n", i, hash[i].chave);
        }
        else
        {
            printf("pos: %d\n", i);
        }
    }
}
void menu()
{
    printf("Tamanho do vetor: %d\n\n", 8);
    printf("1 - Funcao dobra\n");
    printf("2 - Funcao Multiplicacao\n");
    printf("3 - funcao divisao\n");
    printf("0 - SAIR\n");
}
int main()
{
    int opc;
    do
    {
        inicializa_hash();

        menu();
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("AINDA FALTA\n");
            break;
        case 2:
            printf("AINDA FALTA\n");
            break;
        case 3:
            inserir_divisao();
            inserir_divisao();
            inserir_divisao();
            inserir_divisao();
            inserir_divisao();
            inserir_divisao();
            mostrar();
            break;
        case 0:
            system("clear");
            printf("vc saiu...\n");
            break;
        default:
            printf("opccao invalida\n");
            break;
        }
        printf("\n");
    } while (opc != 0);
}