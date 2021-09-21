#include <stdio.h>

//21 - Escreva funções recurivas para calcular:
//b) - Fatorial de um número natural;
//c) - A série de fibonacci (1, 1, 2, 3, 5..., a, b,(a + b). . .);
//d) - isPrime(n): Verificador recursivo se n é um número natural primo.

int mdc(int a,int b)
{
    if(b == 0) {
        return a;
    }else{
        return mdc(b,a%b);
    }
}

double fatorial(int n)
{
    double vfat;
    
    if ( n <= 1 )
        return (1);
    else
    {
        vfat = n * fatorial(n - 1);
        return (vfat);
    }
}

void fib(int limite, int ult = 1, int pen = 0){
    if (limite > 0){
        int prox = ult + pen;
        printf("%d ", prox);
        fib(limite-1, pen, prox);
    }
}

int primo(int num){
    int resultado;
    for (int i = 2; i <= num / 2; i++){
        if (num % i == 0) {
            return printf("Nao e primo");
            break;
        }else{
            return printf("É primo");
        }
    }
}

int main(){
    printf("Minimo Divisor Comum: %d\n", mdc(2,4));

    printf("Fatorial: %.0f", fatorial(5));

    printf("\nFibonacci: ");
    fib(10);

    printf("\n");
    primo(10);
} 