//TRABALHO 3: TORRE DE HANOI
#include <stdio.h>

//FUNÇÃO AUXILIAR    
    void hanoi(int disco, char origemA, char destinoC, char auxiliarB){
    
    if(disco==1){
        printf("Mova o disco 1 da torre %c para %c\n", origemA, destinoC);}
    
    else{
        return        
        hanoi(disco-1, origemA, auxiliarB, destinoC),
        printf("Mova o disco %d da torre %c para %c\n", disco, origemA, destinoC),
        hanoi(disco-1, auxiliarB, destinoC, origemA);}
      }
  

//FUNÇÃO PRINCIPAL
    int main(){    
    int disco;

        printf("Insira o número de discos: ");
        scanf("%d", &disco);
        printf("Para resolver a Torre de Hanoi:\n");

    hanoi(disco, 'A', 'C', 'B');

    return 0;
}
