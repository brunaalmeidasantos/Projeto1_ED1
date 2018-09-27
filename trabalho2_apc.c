//Nathalia Lorena Cardoso - 14/0156909  Lude Yuri Ribeiro - 15/0137770
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *arq;
int **matrizArquivo,caracter, dadosArq[2], somaValores, linhaCentral,colunaCentral, valorDecimal;
char cha[1];

void buscarDadosArq(char *nomeArquivo,int *dadosArq);// pega os dados do arquivo para montar matriz
int binToDec(char *bin); //função criada para converter binario para decimal
char rotacionarBin(char *bin);

int main(){

//por enquanto setando direto depois fazer melhoria para setar o texto de forma randomica
   char nomeArquivo[] = "teste_asfalto1.txt";
 
    buscarDadosArq(nomeArquivo, dadosArq); //alocando a matriz dinamicamente

    
    //alocando matriz dinamicamente
         matrizArquivo = malloc (dadosArq[0] * sizeof (int *));
        for(int i = 0; i < dadosArq[0]; ++i)
             matrizArquivo[i] = malloc (dadosArq[1] * sizeof (int)); //A[i][j]


    arq = fopen(nomeArquivo,"r");         
    //passando valores para matriz         
     for(int i=0;i<dadosArq[0];++i){
         for(int j=0;j<dadosArq[1];++j){ 
             fscanf(arq,"%d%c",&matrizArquivo[i][j],&cha);
            }
        }
    fclose(arq); 
    
    
    //pegando a media das submatrizes dentro da matriz principal
    int colunaFinal = dadosArq[1]-1; //coluna final 
    int linhaFinal = dadosArq[0]-1; //linha final   

    for(int i=1;i<linhaFinal;++i){//inicia na segunda linha e termina antes da ultima
         for(int j=1;j<colunaFinal;++j){//inicia na segunda coluna e termina antes da ultima
       
            int somatorio = 0;//somatorio dos valores da submatriz            
            int pontoCentral = matrizArquivo[i][j]; //ponto central da submatriz  que vai ser o pixel

            somatorio += matrizArquivo[i-1][j-1] + matrizArquivo[i-1][j] + matrizArquivo[i-1][j+1];//linha inicial
            somatorio += matrizArquivo[i][j-1] + pontoCentral + matrizArquivo[i][j+1];//linha do meio
            somatorio += matrizArquivo[i+1][j-1] + matrizArquivo[i+1][j] + matrizArquivo[i+1][j+1];//linha final
                    
            int mediaMatriz = somatorio/9; //media da submatriz
              //printf("Media: %d\n", mediaMatriz);
            
           
            //##############colocando flags 1 e 0 para definir o binario ############################
            char bin[] = "";    //binario vazio do tipo char
            if(matrizArquivo[i-1][j-1] > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }
            if(matrizArquivo[i-1][j] > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }
            if(matrizArquivo[i-1][j+1] > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }
            if(matrizArquivo[i][j-1] > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }
            if(pontoCentral > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }
            if(matrizArquivo[i][j+1] > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }
            if(matrizArquivo[i+1][j-1] > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }
            if(matrizArquivo[i+1][j] > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }
            if(matrizArquivo[i+1][j+1] > mediaMatriz){;
                strcat(bin,"1");
            }else{
                strcat(bin,"0");
            }



              for(int i=0;i<dadosArq[0];++i){
                     for(int j=0;j<dadosArq[1];++j){
                         printf("%d ",matrizArquivo[i][j]);
                     }
                     printf("\n");
                    }
                    printf("Media: %d\n", mediaMatriz);

            printf("Binario: %s \n", bin);
            
            //############ TERMINOU DE COLOCAR AS FLAGS ###############

               
              
                
            valorDecimal = binToDec(bin);
            printf("Decimal: %d \n", valorDecimal);        
            
        
            return 0;
          

         }
    }
    
    
    }


//função criada para buscar dados do arquivo    
 void buscarDadosArq(char *nomeArquivo,int *dadosArq){
     
    arq = fopen(nomeArquivo,"r");
    int comecouPalavra = 0, numPalavras = 0, numLinhas = 1;
    while( (caracter=fgetc(arq))!= EOF ){

          if  ((caracter!=';') && (caracter!='\n') && (!comecouPalavra)) {
             comecouPalavra = 1;
          }
          if  (((caracter==';') || (caracter == '\n')) && (comecouPalavra)) {
             if(numLinhas<2){
                 comecouPalavra = 0;
                 numPalavras++;
            }
          }
          if (caracter=='\n') {
             numLinhas++;
             }
             
             dadosArq[0]=numLinhas;
             dadosArq[1]=numPalavras;
        
            }
       fclose(arq);   
        // printf("\n O número de palavras do arquivo é: %d", dadosArq[0]);
        // printf("\n O número de linhas do arquivo é: %d \n", dadosArq[1]);
       
    }


//função criada para converter binario para decimal  
 int binToDec(char *bin){
    int somatorio = 0;
    int x = 8;
     for(int i = 0; i < 9 ;i++){
          
        if(bin[i] == 49){ // como jogo um binario no formato char comparando com um inteiro tive que compara com 48  => "0"
             somatorio += pow(2, x);                                                                           //49 => "1"
           
        }
        x--;
    };
    return somatorio;
}   
    

    