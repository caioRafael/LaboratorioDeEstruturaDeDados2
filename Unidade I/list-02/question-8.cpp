#include <stdio.h> 

int fatorial(int number){
   int i, fat ;

   if (number <= 1) {
    return 1;
  }

   fat = 1 ;
   for (i=2; i <= number; i++){
      fat *= i ;
   }

   return fat ;
}

int fatorial_aux(int number, int parcial){
  if(number == 1) {
    return parcial;
  } else {
    return fatorial_aux((number-1), (parcial*number));
  }
}

int fatorial_cauda(int number){
  return fatorial_aux(number, 1);
}

int main(){
  int op, fat;
  printf("Escolha o tipo de fatorial:\n");
  printf("1 - Fatorial\n");
  printf("2 - Fatorial com cauda\n");
  printf("3 - Sair\n");
  scanf("%d", &op);
  while (op != 3)
  {
    printf("Digite o número que deseja realizar o fatorial:\n");
    scanf("%d", &fat);
  if (op == 1 )
  {
    printf("O fatorial de %d é %d.\n\n", fat, fatorial(fat));
  } else if ( op == 2){
    printf("O fatorial de %d é %d.\n\n", fat, fatorial_cauda(fat));
  }

  printf("Escolha o tipo de fatorial:\n");
  printf("1 - Fatorial\n");
  printf("2 - Fatorial com cauda\n");
  printf("3 - Sair\n");
  scanf("%d", &op);
  }

}