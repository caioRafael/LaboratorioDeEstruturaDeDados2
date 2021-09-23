#include <stdio.h>
#define TAMANHO 32
typedef struct
{
    int chave;
} HASH;
HASH hash[TAMANHO];
int calc_expoente(int n)
{
    if (n != 0 && n != 1)
    {
        return 2 * calc_expoente(n - 1);
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }
}
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
    int chave2 = chave;
    int aux = chave2;
    int x, tamanho = 0;
    int j;
    do
    {
        aux = aux / 2;
        tamanho++;
    } while (aux != 0);

    int qtd_binarios[tamanho];
    j = tamanho - 1;
    //vai de tamanho até o 1, por isso tem o -1 pra ir do tamanho -1 ao 0
    do
    {
        qtd_binarios[j] = chave2 % 2;
        j--;
        chave2 = chave2 / 2;

    } while (chave2 != 0);

    int total[10], diferença = 10 - tamanho; //10 digitos cada chave deve ter
    for (int i = 0; i < diferença; i++)
    {
        total[i] = 0;
    }
    int inicio = 0;
    for (int i = diferença; i < 10; i++)
    {
        total[i] = qtd_binarios[inicio];
        inicio++;
    }
    //vet[10] preechido

    int p1 = 0, p2 = 0; //metade 1 e metade 2 do vetor de 10 auxsicoes
                        //primeira metade

    inicio = 4;
    for (int i = 0; i < 5; i++)
    {
        p1 = p1 + (total[i] * calc_expoente(inicio));
        tamanho++, inicio--;
    }
    //segunda metade
    inicio = 4;
    for (int i = 5; i < 10; i++)
    {
        p2 = p2 + (total[i] * calc_expoente(inicio));
        tamanho++, inicio--;
    }
    return (p1 ^ p2);
}
int hash_mult(int chave)
{
    //Tamanho hash 32 tem 6 bits,logo pega os 6 do meio
    int aux = chave * chave, tamanho = 0, j; //recebe chave^2
    int chave2 = chave * chave;

    do
    {
        aux = aux / 2;
        tamanho++;
    } while (aux != 0);

    int qtd_binarios[tamanho];
    j = tamanho - 1;
    //tamanho-1 pois o vetor inicia do 0
    do
    {
        qtd_binarios[j] = chave2 % 2;
        j--;
        chave2 = chave2 / 2;

    } while (chave2 != 0);

    int total[TAMANHO], diferença = TAMANHO - tamanho; //32 digitos cada chave deve ter
    //diferença = total de numeros que falta pra preencher as 32 posicoes da chave
    for (int i = 0; i < diferença; i++)
    {
        total[i] = 0;
    }
    int inicio = 0;
    for (int i = diferença; i < TAMANHO; i++)
    {
        total[i] = qtd_binarios[inicio];
        inicio++;
    }
    int meio[6];
    int l = 13; //comeca na posição 14, que no vetor é 13
    for (int i = 0; i < 6; i++)
    {
        meio[i] = total[l];
        l++;
    }

    int numero_meio = 0;

    inicio = 5;
    for (int i = 0; i < 6; i++)
    {
        numero_meio = numero_meio + (meio[i] * calc_expoente(inicio));
        tamanho++, inicio--;
    }
    return numero_meio;
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
        resto = hash_mult(h.chave);
    }
    else if (metodo == 3)
    {
        resto = hash_divisao(h.chave);
    }
    if (hash[resto].chave == -1)
    {
        hash[resto].chave = h.chave;
    }
    printf("\n");
}
void mostrar()
{
    printf("---------TABELA HASH-------------\n");
    for (int i = 0; i < TAMANHO; i++)
    {
        if (hash[i].chave != -1)
        {
            printf("pos: %d\t|chave: %d\n", i, hash[i].chave);
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
    printf("-----------------------------------\n");

    printf("1 - Funcao dobra\n");
    printf("2 - Funcao Multiplicacao\n");
    printf("3 - funcao divisao\n");
    printf("0 ou >3  - SAIR\n");
    printf("-----------------------------------\n");
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
    printf("\n");
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
        printf("FUNCAO HASH DOBRA:\n");
        mostrar();
    }
    else if (opc == 2)
    {
        analisa(opc);
        printf("FUNCAO HASH MULTIPLICACAO:\n");
        mostrar();
    }
    else if (opc == 3)
    {
        analisa(opc);
        printf("FUNCAO HASH DIVISAO:\n");
        mostrar();
    }
    else
    {
        system("clear");
        printf("vc saiu...\n");
    }
    printf("\n");
}