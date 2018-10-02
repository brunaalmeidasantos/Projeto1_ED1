//PROJETO 02 - ESTRUTURA DE DADOS 1
//Bruna ALmeida Santos - 17/0100626 || Natalia Lorena Cardoso - 140156909 || Lude Yuri de Castro Ribeiro - 150137770

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

//**FUNÇÃO 1: SORTEIO DOS ARQUIVOS(seleciona 25 imagens de grama e asfalto, sem repetição)**

int *sorteiaTesteTreino(){
    srand(time(NULL));
    int *n = (int *)malloc(50*sizeof(int));  //alocação dinamica

    int x = 1, y = 0;
    n[0] = rand() % 50 + 1;  //rand = função pra aleatorio
    do
    {
        n[x] = rand() % 50 + 1;
        y = 0;
        while(y < x)
        {
            if(n[y] == n[x])
            {
                x--;
                break; //pra não ocorrer repetição
            }
            y++;
        }
        x++;
    } while(x < 50);

    return n;
  }

////////////////////////////////////////////////////////////////////////////////

//*******FUNÇÃO 2: SALVAR OS ARQUIVOS(salva os arquivos sorteados)**************

int salvaArquivos(int *array, int testeOuTreino, int gramaOuAsfalto){
    char nome[20];
    char diretorio[256];
    char linha[256];
    int i = 0;
    int tipo;

    if(testeOuTreino == 0 && gramaOuAsfalto == 0){  //pra selecionar em qual txt vai ser gravado
        strcpy(nome,"teste_grama.txt");
        strcpy(diretorio,"DataSet/grama/grama_");
        tipo = 0;
    }
    else if (testeOuTreino == 0 && gramaOuAsfalto == 1){
        strcpy(nome,"teste_asfalto.txt");
        strcpy(diretorio,"DataSet/asfalto/asfalto_");
        tipo = 1;
    }
    else if (testeOuTreino == 1 && gramaOuAsfalto == 0){
        strcpy(nome,"treino_grama.txt");
        strcpy(diretorio,"DataSet/grama/grama_");
        tipo = 2;
    }
    else if (testeOuTreino == 1 && gramaOuAsfalto == 1){
        strcpy(nome,"treino_asfalto.txt");
        strcpy(diretorio,"DataSet/asfalto/asfalto_");
        tipo = 3;
    }
    else{
        printf("ERRO");
    }


    FILE *arquivo = NULL;
    arquivo = fopen(nome, "wt");

    int aux, aux2;
    char temp[50];

    for(i = 0; i < 25; i++){  //o que será gravado no txt selecionado
         if(array[i]<10){
            aux = sprintf(temp, "%s0%d.txt\n", diretorio, array[i]);
            fprintf(arquivo,"%s" ,temp);
         }else if(array[i]>=10){
            aux = sprintf(temp, "%s%d.txt\n", diretorio, array[i]);
            fprintf(arquivo, "%s", temp);
        }
    }
    fclose(arquivo);  //fecha o arquivo
    return tipo;
}
////////////////////////////////////////////////////////////////////////////////

//*******FUNÇÃO 3: CASES PARA OS ARQUIVOS(grava as imagens de teste)************

void nomeArquivo(int codigoArquivo, char* nome){
    switch(codigoArquivo){
    case(0):
    strcpy(nome,"teste_grass.txt");
    break;

    case(1):
    strcpy(nome,"teste_asphalt.txt");
    break;

    case(2):
    strcpy(nome,"treino_grass.txt");
    break;

    case(3):
    strcpy(nome,"treino_asphalt.txt");
    break;
    }
}
////////////////////////////////////////////////////////////////////////////////

//************************FUNÇÃO 4: LER O ARQUIVO TXT***************************

void pegaLinhaNome(int codigoArquivo, int linha, char* filename, char* conteudoLinha){
    nomeArquivo(codigoArquivo, filename);
    FILE *fptr;

    fptr = fopen(filename, "r");  //r = read
    rewind(fptr); //vai para o início do arquivo
    int count = 0;
    char buffer[256];  //buffer: vetor de char
    while (fgets(buffer, sizeof buffer, fptr))  //fgets = scanf
    {
        if (count == linha){
            break;
        }
        else{
            count++;
        }
    }

    strtok(buffer, "\n");
    strcpy(conteudoLinha, buffer);
    fclose(fptr);
}
////////////////////////////////////////////////////////////////////////////////

//********************FUNÇÃO 5: CALCULA O TAMANHO DA MATRIZ*********************

int* calculaDimensao(char* filename){
    int *dimensaoMatriz = (int*) calloc (2,sizeof(int)); //alocação

    FILE *arq;
    char c, end = '\n';
    int eol = 0;  //contador


    if ((arq = fopen(filename, "r")) == NULL) {  //verificar abertura do arquivo
        printf("Erro ao abrir o arquivo.");
    }
    else {
        while(fread(&c, sizeof(char), 1, arq)) {
            if (c == '\n'){

                dimensaoMatriz[0]++;
                eol = 1;
            }
            if(c == ';' && eol == 0){
                dimensaoMatriz[1]++;
            }
        }
    }
    dimensaoMatriz[1]++;

    fclose(arq);  //fecha o arquivo.
    return dimensaoMatriz;
}
////////////////////////////////////////////////////////////////////////////////

//*********************FUNÇÃO 6: CALCULAR ILBP (IMCOMPLETO)*********************

void calculaILBP(int *mat[], int lin, int col){
    int i = 0;
    int j = 0;


   int* ilbp = (int *)calloc(pow(2, 9), sizeof(int));  //alocação
   FILE* ilbp_file;
   fopen("ilpb.txt", "w");
}
////////////////////////////////////////////////////////////////////////////////

//**************FUNÇÃO 7: GERAR MATRIZ PARA CALCULAR ILBP***********************

void armazenaArquivoMatriz(char* filename){
    int* dimensaoMatriz;
    dimensaoMatriz = calculaDimensao(filename);
    int lin = dimensaoMatriz[0];
    int col = dimensaoMatriz[1];


    FILE *file;
    file = fopen(filename, "r");

    int **matrizImagem = (int**)calloc(lin,sizeof(int*));  //alocação

    for(int i=0; i<lin; i++){
        matrizImagem[i]=(int*)calloc(col,sizeof(int));  //alocação
    }

    rewind(file);  //sempre ler o arquivo do início.

    if(file==NULL){
    printf("ERRO!\n");
  } else {                         //gera a matriz.
        for(int i=0; i<lin-1; i++){
          for(int j=0; j<col-1; j++){
     	       fscanf(file, "%d%*c", &matrizImagem[i][j]);
	        }
        }
    }


    calculaILBP(matrizImagem, lin, col);

    fclose(file);  //fecha o arquivo.
    free(matrizImagem);  //libera memória
}
////////////////////////////////////////////////////////////////////////////////

//****************************FUNÇÃO PRINCIPAL**********************************

int main () {

	int * ordemImagensAsfalto;
    int * ordemImagensGrama;

    ordemImagensAsfalto = sorteiaTesteTreino();
    sleep(1);
    ordemImagensGrama = sorteiaTesteTreino();

    int asfaltoTreino[25] = {0};
    int asfaltoTeste[25] = {0};
    int gramaTreino[25] = {0};
    int gramaTeste[25] = {0};

    int i;

    for(i = 0; i < (25); ++i){
        asfaltoTreino[i] = *(ordemImagensAsfalto+i);
        gramaTreino[i] = *(ordemImagensGrama+i);
    }

    sleep(1);

    for(; i < 50; ++i){
        asfaltoTeste[i - 25] = *(ordemImagensAsfalto+i);
        gramaTeste[i - 25] = *(ordemImagensGrama+i);
    }

    sleep(1);

    sleep(1);
    int listaArquivosTesteGrama = salvaArquivos(gramaTeste, 0, 0);

    sleep(1);
    int listaArquivosTesteAsfalto = salvaArquivos(asfaltoTeste, 0, 1);

    sleep(1);
    int listaArquivosTreinoGrama = salvaArquivos(gramaTreino, 1, 0);

    sleep(1);
    int listaArquivosTreinoAsfalto = salvaArquivos(asfaltoTreino, 1, 1);

    char arquivoNome[50];
    char conteudoLinha[256];

    int linha, codigoArquivo;

//*************************TREINAMENTO DO SISTEMA*******************************

    for (codigoArquivo = 2; codigoArquivo < 4; codigoArquivo++){
        for (linha = 0; linha < 25; linha++){
            pegaLinhaNome(codigoArquivo, linha, arquivoNome, conteudoLinha);
            sleep(1);
           armazenaArquivoMatriz(conteudoLinha);
        }
    }
}
