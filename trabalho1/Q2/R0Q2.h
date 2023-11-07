#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

//Protótipo das Funções:
void bubbleSortFloat(float arr[], int n);
void ordenaMatriz(char strings[][255],int linhaStrings);
void bubbleSortInt(int arr[], int n);
void bubleSortPoint(float arr[], int n);
float distancia_euclidiana_da_origem(float x, float y);
void OrdenaPoint	(float arr[],int n);

// Funções:
void bubbleSortFloat(float arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n - 1; i++) {
       for (j = i+1; j < n; j++) {
           if (arr[i] > arr[j]) {
               temp = arr[i];
               arr[i] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }
}
void ordenaMatriz(char strings[][255],int linhaStrings){
	int temp;
	 // Percorre todas as linhas da matriz
    for(int i = 0; i < linhaStrings-1; i++) {
        // Percorre todas as linhas restantes da matriz
			for(int j = i + 1; j < linhaStrings; j++) {
            // Compara a primeira coluna de cada linha
				if(strcmp(strings[i],strings[j])>0){
							// Se a primeira coluna da linha i for maior que a primeira coluna da linha j,
							// troca as duas linhas
							char temp[255];                  	
							strcpy(temp,strings[i]);
							strcpy(strings[i],strings[j]);
							strcpy(strings[j],temp);
						}
			}
    }
}
void bubbleSortInt(int arr[], int n){
	int i, j, temp;
   for (i = 0; i < n - 1; i++) {
       for (j = i+1; j < n; j++) {
           if (arr[i] > arr[j]) {
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
   }
}
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