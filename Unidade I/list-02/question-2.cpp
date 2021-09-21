#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

float *gerador(size_t n){    
    srand(time(NULL));
    float *res = (float*) malloc(n * sizeof(float));
    
    
    for (size_t i = 0; i < n; i++){
        res[i] = rand() % 2000;
        
    }
    return res;
}

float sum(float *res, size_t n){
    if(n == 0){
        return 0;
    }else{
        return res[n - 1] + sum(res, n - 1);
    }
}

int main(){

    size_t n;
    printf("Digite a quantidade de elementos a serem gerados: \n");
    scanf("%d", &n);
    
    float *res = gerador(n);    
    
    printf(" Sequencia aleatoria \n");
    for (size_t i = 0; i < n; i++)
    {
        printf("res [%lu]=%.2f\n", i, res[i]);
    }
    
    float avg = sum(res, n) / n;
    printf("Media: %.2f\n", avg);

    return 0;
}