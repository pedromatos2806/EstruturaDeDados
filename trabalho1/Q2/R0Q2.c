#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include "R0Q2.h"

int main() {
	FILE *fp_in = fopen("L0Q2.in", "r"); // um vai ser .in // r de read = ler 
	FILE *fp_out = fopen("L0Q2.out", "w");// vai ser .out // w de write = escrever

	if (fp_in == NULL || fp_out == NULL){
		printf("Arquivos não podem ser abertos.");
		return 1; // retornar EXIT_FAILED (ERRO)!
	}
	char file[255];

	while (fgets(file,255,fp_in)	!=	NULL){
		char *token  = strtok(file," ");
		float point[256];
		int isPoint	=	0;
		float distanceOrigem[128];
		int isDistanceOrigem	=	0;
		float f[255];
		int isFloat =	0;
		int i[255];
		int isInt =	0;
		char strings[1000][255]; //strings[numeroDelinhas][numeroDeCaracteres]
		int linhaStrings = 0;
		
		while(token != NULL ){
			int tam;
			
			tam	=	strlen(token);
			if(strchr(token,'\n') != NULL){
				token[tam-1]	=	'\0';
			}
			if(strchr(token,'(')	!= NULL){
				// È um ponto!
				fflush(stdin);
				sscanf(token,"(%f,%f)", &point[isPoint] , &point[isPoint+1]); 
				distanceOrigem[isPoint/2] =	distancia_euclidiana_da_origem(point[isPoint],point[isPoint+1]);
				isDistanceOrigem++;
				//printf("Ponto: (%.1f,%.1f)\n", point ,point+1);
				isPoint	=	isPoint +	2;
			}else if(isdigit(token[0]) || token[0]	=='-'){
				//É um numero 
				if(strchr(token, '.') != NULL){//é um Float
					f[isFloat] =	atof(token);
					fflush(stdin);
					//printf("f:%.2f\n",f[isFloat]);
					isFloat++;
				}else {
					//é um inteiro
					i[isInt]	= atoi(token);
					fflush(stdin);
					//printf("i:%i\n", i[isInt]);
					isInt++;
				}
			}else{
				//é uma String
				strcpy(strings[linhaStrings], token);
				//printf("str:%s\n", strings[linhaStrings]);
				fflush(stdin);
				linhaStrings++;
			}
			token = strtok(NULL, " ");
		}
		//	Imprimir uma String
		ordenaMatriz(strings, linhaStrings);
		fprintf(fp_out,"str:");
		for(int i=0;	i	< linhaStrings; i++){
				fprintf(fp_out, "%s " ,strings[i]);
		}
		//	Imprimir Int
		bubbleSortInt(i,isInt);
		fprintf(fp_out,"int:");
		for(int j=0;	j	<isInt;	j++){
			fprintf(fp_out,"%i ",i[j]);
			fflush(stdin);
		}
		
		//	Imprimir um Float
		bubbleSortFloat(f,isFloat);
		fprintf(fp_out,"float:");
		for(int i=0;	i	<	isFloat	;i++){
      fprintf(fp_out, "%.2f " ,f[i]);
			fflush(stdin);
		}
		
		//	Imprimir um ponto 
		OrdenaPoint(point,isPoint);
		fprintf(fp_out,"p:");
		fflush(stdin);
		for(int i=0 ;	i	<	isPoint	-1;	i	=	i+2	){
			fprintf(fp_out,	"(%.1f,%.1f) ", point[i], point[i+1]);
			fflush(stdin);
		}
		fprintf(fp_out,"\n");
		fflush(stdin);
	}
	fclose (fp_out); //fechar o file de saída	
	fclose (fp_in);// fechar o file de entrada
}