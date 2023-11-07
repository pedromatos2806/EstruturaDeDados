#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include "R0Q1.h"

int main() {
	FILE *fp_in = fopen("L0Q1.in", "r"); // um vai ser .in // r de read = ler 
	FILE *fp_out = fopen("L0Q1.out", "w");// vai ser .out // w de write = escrever

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
		float Short;
		float Distance;
		while(token != NULL ){
			//quebrar até não ter mais nada p/ ser quebrado
			int tam;
			
			tam	=	strlen(token);
			if(strchr(token,'\n') != NULL){
				token[tam-1]	=	'\0';
			}
			if(strchr(token,'(')	!= NULL){
				// È um ponto!
				fflush(stdin);
				sscanf(token,"(%f,%f)", &point[isPoint] , &point[isPoint+1]); 
				//printf("Ponto: (%.1f,%.1f)\n", point ,point+1);
				isPoint	=	isPoint +	2;
			}
			token = strtok(NULL, " ");
		}
		Short  =  shortcut(point, isPoint);
		Distance =  distance (point,isPoint);
		//	Imprimir um ponto 
		OrdenaPoint(point,isPoint);
		fprintf(fp_out,"points:");
		fflush(stdin);
		for(int i=0 ;	i	<	isPoint	-1;	i	=	i+2	){
			fprintf(fp_out,	"(%1.f,%1.f) ", point[i], point[i+1]);
			fflush(stdin);
		}
		fprintf(fp_out,"distance %.2f ", Distance);
		// Imprimir o shortcut
		fprintf(fp_out,"shortcut %.2f ", Short);
		fprintf(fp_out,"\n");
		fflush(stdin);
	}
	fclose (fp_out);
	fclose (fp_in);
}