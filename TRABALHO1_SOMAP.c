//TRABALHO 1: SOMA P
#include <stdio.h>
#define MAX 10

    
    //FUNÇÃO AUXILIAR
    int fneuronio(int *entradas, int *pesos, int*limiarT){
        int somaP = 0;
        int aux = 0;
        
        for(aux = 0; aux<MAX; aux++){
            somaP += entradas[aux] * pesos[aux];
        }
    if(somaP > *limiarT)
        return 1;
    else
        return 0;
    }
    
    //FUNÇÃO PRINCIPAL
    int main(){
        int entradas[MAX];  
        int pesos[MAX];
        int limiarT;
        int aux = 0, neuronio = 0;

    printf("Digite as entradas:\n");
        for(aux = 0; aux<MAX; aux++)
        {scanf("%d", &entradas[aux]);}    
    
    printf("Digite os pesos:\n");
        for(aux = 0; aux<MAX; aux++)
        {scanf("%d", &pesos[aux]);}

    printf("Digite o limiar:\n");
        scanf("%d", &limiarT);
    

    neuronio = fneuronio(entradas, pesos, &limiarT);

        if(neuronio == 1)
            {printf("Neurônio ativado!\n");}
        else if(neuronio == 0)
            {printf("Neurônio inibido!\n");}

    return 0;
    }
