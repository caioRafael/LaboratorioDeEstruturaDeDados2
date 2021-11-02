/*
Discentes:
  Caio Rafael da Rocha Gomes - 2020010301
  Eduardo Pereira Carlos - 2020010490
  Jonas Henrique da Silva Lins - 2020010428
  Ryam de Sousa Alves - 2020010159
  Paulo Vitor Lopes da Silva - 2020010310
  Paulo Fernandes Vieira - 2020010790

  Input data example:
  7 0 0 2 0 0 0 5 3
  0 0 3 0 0 0 1 6 4
  0 1 8 3 5 0 0 9 0
  0 3 9 5 0 1 0 8 7
  1 0 0 0 2 0 0 3 0
  8 0 0 7 0 9 0 0 1
  0 7 2 4 6 5 3 0 0
  0 8 6 1 7 0 0 2 5
  3 0 1 9 8 0 4 7 6
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define V 81
int color[V];
int matrizD[81][81];
int order = 9;

int generateRoot(int number)
{
  int aux = number / 2;
  for (int i = 0; i <= aux; i++)
  {
    if ((i * i) == number)
    {
      return i;
    }
  }
  return 0;
}

void generateMatrizS()
{
  int vertexNumber = (order * order);
  int raiz = generateRoot(order);
  for (int i = 0; i < vertexNumber; i++)
  {
    for (int j = 0; j < vertexNumber; j++)
    {
      if (j >= (i / order) * order && j < (i / order) * order + order)
        matrizD[i][j] = 1; //Verify line
      else if (j % order == i % order)
        matrizD[i][j] = 1; //Verify column
      else
        matrizD[i][j] = 0;
    }
  }

  for (int i = 0; i < vertexNumber; i++)
  {
    for (int f = 0; f < raiz; f++)
    {
      for (int k = 0; k < raiz; k++)
      {
        if ((i / order) % raiz == 0)
          for (int j = 0; j < raiz; j++)
          {
            matrizD[i + order * f][(i / raiz) * raiz + j + order * k] = 1; //Verify line and column
          }
      }
    }
  }

  for (int i = 0; i < vertexNumber; i++)
  {
    for (int j = 0; j < vertexNumber; j++)
    {
      if (i == j)
      {
        matrizD[i][j] = 3;
      }
    }
  }
}

void showGenerateMatriz(int color[]);

int isSafe(int v, int grafo[V][V], int color[], int c)
{
  for (int i = 0; i < V; i++)
    if (grafo[v][i] == 1 && c == color[i])
      return 0;
  return 1;
}
int grafoColoreRecursive(int grafo[V][V], int m, int color[], int v)
{
  if (v == V)
  {
    return 1;
  }

  if (color[v] != 0)
  {
    if (grafoColoreRecursive(grafo, m, color, v + 1) == 1)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }

  for (int c = 1; c <= m; c++)
  {
    if (isSafe(v, grafo, color, c))
    {
      color[v] = c;
      if (grafoColoreRecursive(grafo, m, color, v + 1) == 1)
      {
        return 1;
      }
      color[v] = 0;
    }
  }

  return 0;
}

int grafoColore(int grafo[V][V], int m)
{

  if (grafoColoreRecursive(grafo, m, color, 0) == 0)
  {
    printf("\nNao foi possível achar uma solução!");
    return 0;
  }

  printf("\nMatriz gerada com o número mínimo de cores = %d", m);
  showGenerateMatriz(color);
  return 1;
}

void showGenerateMatriz(int color[])
{
  int raiz = generateRoot(order);
  for (int i = 0; i < V + 1; i++)
  {
    if (i % raiz == 0 && (i != 0))
    {
      printf("|");
    }
    if (i % order == 0)
    {
      printf("\n");
    }
    if (i % (order * raiz) == 0)
    {
      printf("---------------------------------------\n");
    }
    if (i <= V - 1)
    {
      printf(" %.2d ", color[i]);
    }
  }
}

int main()
{
  generateMatrizS();
  //Reading input data
  for (int i = 0; i < V; i++)
  {
    scanf("%d", &color[i]);
  }
  printf("Matriz gerada com os dados inseridos:");
  showGenerateMatriz(color);

  int m = order;
  grafoColore(matrizD, m);
  printf("\n");

  return 0;
}