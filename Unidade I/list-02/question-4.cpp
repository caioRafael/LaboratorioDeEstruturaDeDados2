#include <iostream>
//Binomio de newton - combinação
/*
    Como funciona o calculo com exemplo: (3,2) = (2,1)+(2,2) aplicando a formula
    e por exemplo deu (2,1)+(2,2) mas n sabe os valores dessas cordenadas, ai como é recursiva
    o ciclo se repete até ser (1,1) que é igual a = (0,0)+(0,1), onde (0,1) não existe pois
    k > n, sendo =0(relativo a nada) e 0+1 =1
*/
int binomio(int n, int k)
{
    if ((k == 0) || (n == 0) || (n == k))
    {
        return 1;
    }
    else
    {
        return (binomio(n - 1, k - 1) + binomio(n - 1, k));
    }
}
int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    while (k > n)
    {
        printf("ERRO: K é maior que N, digite novamente:\n");
        scanf("%d %d", &n, &k);
    }
    printf("Resultado de (%d, %d):%d\n", n, k, binomio(n, k));
}