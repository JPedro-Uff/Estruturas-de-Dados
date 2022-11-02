#include <stdio.h>
#include <stdlib.h>


typedef struct arvbin{
    int chave;
    struct arvbin* dir;
    struct arvbin* esq;
}TAB;

typedef struct lista{
    int info;
    struct lista *prox;
}TLista;

TLista* cria_lista(void){
    return NULL;
}

void imprime_lista(TLista* li){
    TLista* p;
    for (p = li; p != NULL; p = p->prox) printf("%d | ", p->info);
    printf("\n\n");
}

TAB *criaRaiz(int i){
    TAB *novo = (TAB*) malloc (sizeof(TAB));
    novo -> chave = i;
    novo -> esq = NULL;
    novo -> dir = NULL;
    return novo;
}

TLista* insere_fim(TLista* li, int i){
    TLista *novo = (TLista*) malloc (sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li;
    if (p == NULL) li = novo;
    else {
        while(p->prox){
            p = p -> prox;
        }
        p -> prox = novo;
    }
    return li;
}

TLista *menores(TAB *no, int n){
    TLista *ListaMen = cria_lista();
    if(no){
        if(no->chave < n) ListaMen = insere_fim(ListaMen, no ->chave);
        else ListaMen = insere_fim(ListaMen, -1);

        if(no ->dir) ListaMen ->prox = menores(no->dir, n);
        if(ListaMen ->prox && no ->esq) ListaMen ->prox ->prox = menores(no->esq, n);
        else if(no ->esq) ListaMen ->prox = menores(no->esq, n);
        return ListaMen;
    }
}

TAB *insereOrd(TAB* no, int i){
    if(!no) return criaRaiz(i);
    else if(i < no->chave) no -> esq = insereOrd(no->esq, i);
    else if(i > no->chave) no -> dir = insereOrd(no->dir, i);
    return no;
}

void imprimeAux(TAB* no, int h){
    int j;
    if(no){
        imprimeAux(no -> dir, h + 1);
        for(j = 0; j < h; j++) printf("\t");
        printf("%d\n", no -> chave);
        imprimeAux(no->esq, h + 1);
    }
    else{
        for(j = 0; j <= h; j++) printf("\t");
        printf("N\n");
    }
}

void imprimeArv(TAB* raiz){
    imprimeAux(raiz, 0);
}

int fatorBalanceamento(TAB *no, int h){
    if(no){
        h = altura(no->dir, h + 1) - altura(no->esq, h + 1);

    }


}

int main(void){
    int i;
    TAB *arvTest;
    TLista *lista;
    
    while(1){
        scanf("%d", &i);
        if(i<0)break;
        arvTest = insereOrd(arvTest, i);
    }
    imprimeArv(arvTest);
    printf("\n\n---------------------------------\n\n");
    printf("%d", fatorBalanceamento(arvTest, 0));
//    scanf("%d", &i);
//    printf("\n");
//    lista = menores(arvTest , i);
//    imprime_lista(lista);
}