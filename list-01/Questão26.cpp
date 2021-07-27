#include <stdio.h>
#include <conio.h>
//26 - Defina a recursivamente a Função de Ackermann A(m,n):
// I - n+1, se m = O
//II - A(m − 1, 1), se m > 0, n = 0.
//III- A(m − 1, A(m, n − 1)), se m > 0, n > 0

int ack(int x,int y){
	if(x==0){
		return y+1;
	}
	if(y==0){
		return x-1, 1;
		return ack(x-1,(ack, x-1,1));
	}
}

int main()
{
	for (int x = 0; x <5; x++){
	 	for (int y = 0; y <5; y++){
	 		printf("ack(%d,%d) = %d\n", x, y, ack(x,y));
		}
	}
	return 0;
}