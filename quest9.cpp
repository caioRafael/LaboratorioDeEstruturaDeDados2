#include <iostream>

int main() {
   
    int x = 0;
    printf("num --- char\n");
    for (int y = 0; y<= 127; y++){
        x++;
        printf(" |%d -> %c| ",y,y);

        if(x == 10) {
            printf("\n");
             x=0;}
    }

    return 0;
}