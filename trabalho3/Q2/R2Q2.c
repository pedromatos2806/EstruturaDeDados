#include "R2Q2.h"

int main()
{
    FILE* arqIn = fopen("L2Q2.in", "r");
    FILE* arqOut = fopen("L2Q2.out", "w");
    if(arqOut == NULL || arqIn == NULL){
        printf("ERRO AO ABRIR ARQUIVOS");
        return 0;
    }
    avbin* raiz = criaArvore();  
    char linha[256], *token;
    int nun, cont = 0;
    int retorno = 0;
    while(fgets(linha, 256, arqIn) != NULL){
        token = strtok(linha, " ");
        if(cont != 0)
            fprintf(arqOut, "\n");
        while(token != NULL){
            nun = atoi(token);
            inserir(raiz, nun);
            token = strtok(NULL, " ");
        }
        emOrdem(raiz, arqOut, &retorno);
        destruirArvore(raiz);
        avbin* raiz = criaArvore(); 
        cont++;
        retorno = 0;
    }
    destruirArvore(raiz);
    return 1;
}