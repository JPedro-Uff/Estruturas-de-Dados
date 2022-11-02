#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLista;

TLista* cria_lista(void);

TLista* insere_inicio(TLista* li, int i);

TLista* insere_fim(TLista* li, int i);

TLista* retira(TLista* li, int i);

int verificaOrd(TLista* li);

void ordena(TLista* li);

TLista* inverte1(TLista *li);

void imprime_lista(TLista* li);

float tamanho(TLista* li);

void inverte2(TLista* li);

#endif