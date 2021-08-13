#include <stdio.h>
#include <time.h>

int algoritmoDemorado(int n);

int main(){
    clock_t time;

    time = clock();
    
    algoritmoDemorado(1000);
    
    time = clock() - time;    

    float timeSec = (double) time / (CLOCKS_PER_SEC / 1000);
    
    printf("%f", timeSec);
    
    return 0;
}

int algoritmoDemorado(int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    soma = i+j+k+l;
                }
            }
        }
    }
    return soma;
}
