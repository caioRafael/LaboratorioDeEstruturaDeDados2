#include <stdio.h>
#include <stdlib.h>

//a função basicamente esta trocando as posições do meu vetor
//com a utilização de uma variavel auxiliar
float invert(int vet[], int inicio, int fim){
	int aux;
	if(inicio<fim){
		aux = vet[inicio];
		vet[inicio] = vet[fim];
		vet[fim] = aux;
		invert(vet, inicio+1, fim-1);
	}
}

int main (){
	
	int vet[10]={3,4,5,3,2,1,3,41,11,22}; //definindo tamanho e os valores que vão ser impressos

	printf("Vetor Original: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", vet[i]);//apenas exibindo o vetor sem alterações
	}
	printf("\n");

	invert(vet, 0, 9);//passado vator o ponto inicial e o ponto final
	printf("Vetor Trocado: ");
	for (int i=0; i<10; i++){
		printf("%d ", vet[i]);//exibindo o vetor com os valores alterados
	}
	return 0;
}