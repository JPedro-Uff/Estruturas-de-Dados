#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLista;

TLista* insere_inicio(TLista* li, int i){
    TLista *novo = (TLista*) malloc (sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

float tamanho(TLista* li){
    if(!li)return 0;
    float t = 0;
    while(li) {
        li = li -> prox;
        t++;
    }
    return t;
}

void inverte2(TLista* li){
    TLista *auxFim = NULL, *auxInicio = li, *aux = li;
    float tam = (tamanho(li))/2;
    int numAux;
    while(tam >= 1){
        while(aux->prox != auxFim) aux = aux -> prox;
        auxFim = aux;
        numAux = auxInicio -> info;
        auxInicio -> info = auxFim -> info;
        auxFim -> info = numAux;
        auxInicio = auxInicio -> prox;
        aux = auxInicio;
        tam--;
    }
}

void imprime_lista(TLista* li){
    TLista* p;
    for (p = li; p != NULL; p = p->prox) printf("%d | ", p->info);
    printf("\n\n");
}


int main(void){
    TLista *lista = (TLista*) malloc(sizeof(TLista));
    lista = NULL;
    lista = insere_inicio(lista, 1);
    lista = insere_inicio(lista, 2);
    lista = insere_inicio(lista, 3);
    lista = insere_inicio(lista, 4);
    lista = insere_inicio(lista, 5);
    imprime_lista(lista);
    inverte2(lista);
    imprime_lista(lista);
}