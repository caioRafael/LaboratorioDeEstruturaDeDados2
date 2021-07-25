// Problema 17 Escreva uma função que considere o tempo como três argumentos inteiros (para horas, minutos e segundos) e retorne o número de
// segundos desde a última vez que o relógio bateu 12. Use esta função para calcular a quantidade de tempo em segundos entre dois tempos, ambos dentro
// de um ciclo de 12 horas do relógio.

#include <stdio.h>

void getTimeDiferenceBetween12(int hours, int minutes, int seconds){
  int time = ((hours * 60 * 60) + ( minutes * 60) + seconds);
  int twelve = (12 * 60 * 60);
  int timePast = 0;

  if( time >= twelve){
    timePast = time - twelve;
  } else if ( time < twelve ){
    timePast = ((12 * 60 * 60) + (twelve - time));
  }

  printf( "O tempo em segundos desde que bateu 12PM é: %d\n", timePast);

}

int main(){
  int hours, minutes, seconds;

  printf("Insira as horas, minutos e segundos: ");
  scanf("%d %d %d", &hours, &minutes, &seconds);

  getTimeDiferenceBetween12(hours, minutes, seconds);
}