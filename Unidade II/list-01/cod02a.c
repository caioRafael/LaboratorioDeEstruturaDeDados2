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

int escolher_metodo(int chave, int metodo)
{
  switch (metodo)
  {
  case 1:
    return hash_dobra(chave);
    break;
  case 2:
    return hash_mult(chave);
    break;
  case 3:
    return hash_divisao(chave);
    break;
  default:
    break;
  }
}

void inserir(int metodo)
{
  HASH h = preencher();
  int resto = escolher_metodo(h.chave, metodo);

  //Tratando colisão, uma vez que ele verifica se na posição do resto não possui o -1 que no qual tem como finalidade
  //avisar que a posição está vazia, ele faz o mesmo procedimento anterior só que dessa vez incrementando para a próxima posição;

  while (hash[resto].chave != -1)
  {
    int resto = escolher_metodo((resto + 1), metodo);
  }

  if (hash[resto].chave == -1)
  {
    hash[resto].chave = h.chave;
  }
  printf("\n");
}

HASH *buscar(int chave, int metodo)
{
  int resto = escolher_metodo(chave, metodo);
  while (hash[resto].chave != -1)
  {
    if (hash[resto].chave == chave)
    {
      return &hash[resto];
    }
    else
    {
      resto = escolher_metodo((resto + 1), metodo);
    }
  }
  return NULL;
}

int remover(int chave, int metodo){
  int resto = escolher_metodo(chave, metodo);
  while (hash[resto].chave != -1)
  {
    if (hash[resto].chave == chave)
    {
      return resto;
    }
    else
    {
      resto = escolher_metodo((resto + 1), metodo);
    }
  }
  return -1;
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
  printf("-----------------------------------\n");
  printf("1 - Mostrar tabela\n");
  printf("2 - Inserir uma chave\n");
  printf("3 - Buscar chave\n");
  printf("4 - Remover chave\n");
  printf("0 - Finalizar algoritmo\n");
  printf("Tamanho do vetor: %d\n", TAMANHO);
  printf("-----------------------------------\n");
}

void menu_funcoes()
{
  printf("\n\n-----------------------------------\n");
  printf("Escolha a função de mapeamento:\n");
  printf("1 - Função Dobra\n");
  printf("2 - Função Multiplicação\n");
  printf("3 - Função Divisão\n");
}

//deprecated
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
  int metodo;
  int resto;

  inicializa_hash();

  menu();
  scanf("%d", &opc);

  do
  {
    switch (opc) {
    case 1:
      mostrar();
    break; 
    case 2:
      menu_funcoes();
      scanf("%d", &metodo);
      do
      {
        inserir(metodo);
        
        menu_funcoes();
        printf("4 - Parar de inserir\n");
        scanf("%d", &metodo);
      } while (metodo != 4);
    break;

    case 3: 
      menu_funcoes();
      scanf("%d", &metodo);
      do
      {
        HASH *hash;
        int chave;
        printf("Pesquisar chave:\n");
        scanf("%d", &chave);
        hash = buscar(chave, metodo);
        if (hash != NULL){
          printf("Chave: %d\n", hash->chave);
        } else {
          printf("Chave não encontrada!\n");
        }

        menu_funcoes();
        printf("4 - Parar de buscar\n");
        scanf("%d", &metodo);
      } while (metodo != 4);
      break;
    case 4:
      menu_funcoes();
      scanf("%d", &metodo);
      do
      {
        int chave;
        printf("Qual chave você deseja remover?\n");
        scanf("%d", &chave);
        resto = remover(chave, metodo);
        if (resto != -1){
          hash[resto].chave = -1;
          printf("Chave removida com sucesso!\n");
        } else {
          printf("Chave não encontrada!\n");
        }

        menu_funcoes();
        printf("4 - Parar de remover\n");
        scanf("%d", &metodo);
      } while (metodo != 4);
    break;
    default:
      break;
    }

    menu();
    scanf("%d", &opc);
  } while (opc != 0);
}