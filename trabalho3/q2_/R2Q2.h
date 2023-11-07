#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct no{
    struct no* esq;
    struct no* dir;
    int valor;
    int somaDir;
    int somaEsq;
}no;

typedef no* avbin;
avbin* criaArvore();
void destruirNo(no* no);
void destruirArvore(avbin* raiz);
void inserir(avbin* raiz, int valor);
no* percorre(no* atual, no* pai, int valor, int flag);
int* emOrdem(avbin* raiz, FILE* arq, int* retorno);


avbin* criaArvore(){
    avbin* raiz = (avbin*)malloc(sizeof(avbin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
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


no* percorre(no* atual, no* pai, int valor, int flag){
    if(atual == NULL)
        return pai;
    pai = atual;
    if(valor < atual->valor){
        if(flag)
            atual->somaEsq += valor;
        return percorre(atual->esq, pai, valor, flag);
    }else if(valor > atual->valor){
        if(flag)
            atual->somaDir += valor;
        return percorre(atual->dir, pai, valor, flag);
    }else
        return NULL;
}


void inserir(avbin* raiz, int valor){
    no* novo = (no*)malloc(sizeof(no));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->valor = valor;
    novo->somaDir = 0;
    novo->somaEsq = 0;
    
    if(*raiz == NULL){
        *raiz = novo;
        return;
    }
    no* atual = *raiz;
    no* ant = atual;
    ant = percorre(atual, ant, valor, 0);
    if(ant == NULL)
        return;
    if(valor < atual->valor || valor > atual->valor)
        atual = percorre(atual, ant, valor, 1);
    else
        atual  = NULL;
    if(atual != NULL){
        if(valor < atual->valor){
            atual->esq = novo;
        }else if(valor > atual->valor){
            atual->dir = novo;
        }    
    }else
        free(novo);   
}


int* emOrdem(avbin* raiz, FILE* arq, int* retorno){
    if(*raiz == NULL){
        *retorno+=1;
        return retorno;
        }
    else{
        emOrdem(&((*raiz)->esq), arq, retorno);
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            if(*retorno == 1)
                fprintf(arq, "%d (0)", (*raiz)->valor); 
            else
                fprintf(arq, " %d (0)", (*raiz)->valor);
        }else if((*raiz)->esq == NULL){
            if(*retorno == 1)
                fprintf(arq, "%d (%d)", (*raiz)->valor, (*raiz)->somaDir);
            else
                fprintf(arq, " %d (%d)", (*raiz)->valor, (*raiz)->somaDir);
        }else if((*raiz)->dir == NULL){
            if(*retorno == 1)
                fprintf(arq, "%d (%d)", (*raiz)->valor, (0 - (*raiz)->somaEsq));    
            else
                fprintf(arq, " %d (%d)", (*raiz)->valor, (0 - (*raiz)->somaEsq));
        }else{
            if(*retorno == 1)
                fprintf(arq, "%d (%d)", (*raiz)->valor, ((*raiz)->somaDir - (*raiz)->somaEsq));
            else
                fprintf(arq, " %d (%d)", (*raiz)->valor, ((*raiz)->somaDir - (*raiz)->somaEsq));            
        }
        emOrdem(&((*raiz)->dir), arq, retorno);
    }
}