#include <stdio.h>
#include <conio.h>

//22 - Defina uma função recursiva que, dado os valores inteiros de
//     x1 e x2, determine y = x1x2.

int func (int x1, int x2){
    return x1*x2;
}

int main(){

    int x1, x2;

    printf("Valor de Y = %d", func(2, 4));
    
}