#ifndef ARVBIN_H
#define ARVBIN_H

#include <stdio.h>
#include <stdlib.h>
#include "../ListaEncad/Lista.h"

typedef struct arvbin{
    int chave;
    struct arvbin* dir;
    struct arvbin* esq;
}TAB;

TAB *criaRaiz(int i);
void imprimeAux(TAB* no, int h);
void imprimeArv(TAB* raiz);
TAB *insereOrd(TAB* no, int i);
TAB *busca(TAB* no, int i);
TAB *copia(TAB* no);
TAB *espelho(TAB* no);
int maiorAux(TAB* no, int n);
int maiorInt(TAB* raiz);
TAB *maiorNo(TAB* no);
TAB *excluiPares(TAB* no);
TLista *ancestrais(TAB* no, int elem);
TLista *menores(TAB* no, int n);
int calculaFilhos(TAB *no);

#endif