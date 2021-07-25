#include <iostream>
#include <string.h>

void point (int lado1, int lado2);

int main() {
    int lado1, lado2;

    printf("digite nuemro de linhas e numero de colunas\n");
    scanf("%d %d", &lado1, &lado2);
    point(lado1, lado2);

    return 0;
    
}

void point (int lado1, int lado2){
    char caxota[lado1][lado2];
    for(int x = 0; x < lado1; x++){
        for(int y = 0; y < lado2; y++){
            strcpy(&caxota[x][y], "*");
        }
    }
    for(int x = 0; x < lado1; x++){
        for(int y = 0; y < lado2; y++){
            printf("%c ", caxota[x][y]);
        }
        printf("\n");
    }
}