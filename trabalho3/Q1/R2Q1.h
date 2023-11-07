// Alunos:	IGOR PAIM e PEDRO MATOS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


typedef struct no{
    struct no* esq;
    int nun;
    struct no* dir;
    int alt;
}no;

typedef no* avbin;

typedef struct saida{
    int valor;
    int alt;
    int ant;
}saida;

avbin* criaArvore();
no* percorre(no* atual, int valor, no* ant, int alt);
saida inserir(avbin* raiz, FILE* arq, int valor);
void destruirNo(no* no);
void destruirArvore(avbin* raiz);

avbin* criaArvore(){
    avbin* raiz = (avbin*)malloc(sizeof(avbin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}


no* percorre(no* atual, int valor, no* ant, int alt){
    if(atual == NULL){
        ant->alt = alt;
        return ant;
    }
    ant = atual;
    if(valor < atual->nun){
        percorre(atual->esq, valor, ant, alt+1);
    }else{
        percorre(atual->dir, valor, ant, alt+1);
    }
}


 saida inserir(avbin* raiz, FILE* arq, int valor){
    int alt = 0;
    saida output;
    no* novo = (no*)malloc(sizeof(no)); 
    novo->dir = NULL;
    novo->esq = NULL;
    novo->nun = valor;
    if(*raiz == NULL){
        *raiz = novo;
        fprintf(arq, "0");
        output.valor = novo->nun;
        output.alt = 0;
        return output;
    }
    no* atual = *raiz;
    if(valor < atual->nun)
        atual = percorre(atual->esq, valor, atual, alt);
    else
        atual = percorre(atual->dir, valor, atual, alt);
    if(valor < atual->nun){
        atual->esq = novo;
        fprintf(arq, " %d", atual->alt+1);
        output.valor = novo->nun;
        output.alt = atual->alt+1;
        return output; 
    }
    else{
        atual->dir = novo;
        fprintf(arq, " %d", atual->alt+1);
        output.valor = novo->nun;
        output.alt = atual->alt+1;
        return output;
    }
}


void destruirNo(no* no){
    if(no == NULL)
        return;
    destruirNo(no->esq);
    destruirNo(no->dir);
    free(no);
    no = NULL;
}


void destruirArvore(avbin* raiz){
    if(*raiz == NULL)
        return;
    destruirNo(*raiz);
    free(raiz);
}