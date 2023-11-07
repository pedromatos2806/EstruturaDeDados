#include "R1Q3.h"

int main(){
  char linha[256], *token;
  int i = 0, cont = 0, numero, j = 0;
	FILE *fp_in = fopen("L1Q3.in", "r");  
	FILE *fp_out = fopen("L1Q3.out", "w");
	if (fp_in == NULL || fp_out == NULL){ 
		printf("Arquivos não podem ser abertos.");
		return EXIT_FAILURE; 
	}
  int* vetorInt = (int*)malloc(sizeof(int)*100);
  float* vetorFloat = (float*)malloc(sizeof(float)*100);
  int contQuebraLinha = 0;
  while(fgets (linha,	256, fp_in)	!= NULL){
    if(contQuebraLinha != 0)
      fprintf(fp_out, "\n");
    contQuebraLinha++;
    i = 0; j = 0;
    token = strtok(linha, " ");
    while(token != NULL){
			int tamanho	=	strlen(token);
			if (token[tamanho-1]	==	'\n'){
				token[tamanho-1]	=	'\0';
			}
      verifica_caracter(token, &cont); 
      if(cont == E_CARACTERE){
        cont = 0;  
      }else{
      	double numero = atof(token);
       	int retorno	=	 intOrFloat	(numero);
					if (retorno	==	INTEIRO){
						vetorInt[i] = (int)numero;
            i++;
					}else{
						vetorFloat[j] = (float)numero;
            j++;
					}
      }
      token = strtok(NULL, " ");
    }
    inicioSublista* sublista = (inicioSublista*)malloc(sizeof(inicioSublista)*i);
    for(int y = 0; y < i; y++){
      sublista[y].qtdElementos = 0;
      sublista[y].primeiroElemento = NULL;
    }
    inicio* lista = (inicio*)malloc(sizeof(inicio));
    lista->qtdElementos = 0;
    lista->primeiroElemento = NULL;
    insertionSort(vetorInt, i);
    insertionSortFloat(vetorFloat, j);

    for(int k = 0; k < i; k++){
      inserirElementoFinal(lista, vetorInt[k], &sublista[k]);
      for(int h = 0; h < j; h++){
        if(vetorFloat[h]<vetorInt[k])
          continue;
        else if(vetorFloat[h]>vetorInt[k] && vetorFloat[h]<vetorInt[k]+1){
          inserirElemento(&sublista[k], vetorFloat[h]);
        }
      }
    }
    impressao(lista, fp_out);
    liberaMemoria(lista);
  }

	fclose(fp_out);
	fclose(fp_in);
}