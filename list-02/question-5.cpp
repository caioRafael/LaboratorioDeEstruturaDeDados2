#include <iostream>
/*
Problema) Desenvolva um algoritmo contFib(n, k) que determina quantas vezes o fib(k) é 
avaliado durante a procura de fib(n). (Considere k<n)
*/
int cont = 0;
int contFib(int n, int k)
{
    int resul;
    if (n == k)
    {
        cont++;
    }
    else if ((n != 1) && (n != 0))
    {
        contFib(n - 1, k);
        contFib(n - 2, k);
    }
    return cont;
}
int main()
{
    int n, k;
    printf("Digite valores para fib(n,k):\n");
    scanf("%d %d", &n, &k);
    printf("fib(%d,%d)= %d vezes\n", n, k, contFib(n, k));
}