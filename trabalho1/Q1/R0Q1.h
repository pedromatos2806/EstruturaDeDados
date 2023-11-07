#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

//Protótipo das Funções:	
float distancia_euclidiana_da_origem(float x, float y);
void OrdenaPoint	(float arr[],int n);
float shortcut(float arr[], int tamanho);
float distance (float arr[], int tamanho);

float distancia_euclidiana_da_origem(float x, float y) {
    return sqrt(	pow(x, 2) + pow(y, 2)	);
}
void OrdenaPoint	(float arr[],int n){
	int i,j,temp,tempP;
	float p1,p2;
	for( i	=	0; i	<	n-1 ; i=i+2){
		for( j	=	i+2;	j	<	n	;	j=j+2){
      p1 = distancia_euclidiana_da_origem( arr[i],  arr[i+1]);
      p2 = distancia_euclidiana_da_origem( arr[j],  arr[j + 1]);
			if(	p1 > p2){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
							
				tempP = arr[i+1];
				arr[i+1]=arr[j+1];
				arr[j+1]=tempP;
			}
		}
	}
}
float shortcut(float arr[], int tamanho) {
	float soma_quadrados = 0;
	soma_quadrados = pow( (arr[tamanho-2])	- (arr[0]), 2) + pow(	(arr[tamanho-1]) - (arr[1]), 2);
	return sqrt(soma_quadrados);
}
float distance (float arr[], int tamanho){
	float soma	=	0;
	for (int i=0 ; i	<	tamanho-3 ; i=i+2){
		soma = soma +  sqrt(pow( (arr[i+2])-(arr[i]), 2) + pow(	(arr[i+3])-(arr[i+1]) , 2));
		//printf("%f %f %f %f\n",arr[i+2] ,arr[i] , arr[i+3], arr[i+1]);
	}
	//printf("soma:%f\n", soma);
	return soma;
}