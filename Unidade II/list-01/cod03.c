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
    do
    {
        qtd_binarios[j] = chave2 % 2;
        j--;
        chave2 = chave2 / 2;

    } while (chave2 != 0);

    int total[10], diferença = 10 - tamanho;
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
    int aux = chave * chave, tamanho = 0, j; //recebe chave^2
    int chave2 = chave * chave;

    do
    {
        aux = aux / 2;
        tamanho++;
    } while (aux != 0);

    int qtd_binarios[tamanho];
    j = tamanho - 1;
    do
    {
        qtd_binarios[j] = chave2 % 2;
        j--;
        chave2 = chave2 / 2;

    } while (chave2 != 0);

    int total[TAMANHO], diferença = TAMANHO - tamanho;
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
    int l = 13;
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

void inserir(int metodo, int chave)
{
    HASH h;
    h.chave = chave;
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

int main()
{
    int opc;

    inicializa_hash();
    menu();
    scanf("%d", &opc);
    if (opc == 1)
    {
        inserir(opc, 71);
        inserir(opc, 46);
        inserir(opc, 15); //não insere
        inserir(opc, 28);
        inserir(opc, 56);
        inserir(opc, 120);
        inserir(opc, 9);
        inserir(opc, 21);
        printf("FUNCAO HASH DOBRA:\n");
        mostrar();
    }
    else if (opc == 2)
    {
        inserir(opc, 40);
        inserir(opc, 120);
        inserir(opc, 135);
        inserir(opc, 200);
        inserir(opc, 215);
        inserir(opc, 500);
        inserir(opc, 400);
        inserir(opc, 310);
        inserir(opc, 490);
        inserir(opc, 140); //não insere
        printf("FUNCAO HASH MULTIPLICACAO:\n");
        mostrar();
    }
    else if (opc == 3)
    {
        inserir(opc, 33);
        inserir(opc, 64);
        inserir(opc, 15);
        inserir(opc, 16);
        inserir(opc, 21);
        inserir(opc, 40);
        inserir(opc, 5);
        inserir(opc, 63);
        inserir(opc, 37); //esse não prenche pois ja tem um elemento na posicao 5
        printf("FUNCAO HASH DIVISAO:\n");
        mostrar();
    }
    else

    {
        printf("vc saiu...\n");
    }
    printf("\n");
}