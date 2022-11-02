#include "Lista.h"

TLista* cria_lista(void){
    return NULL;
}

TLista* insere_inicio(TLista* li, int i){
    TLista *novo = (TLista*) malloc (sizeof(TLista));
    novo->info = i;
    novo->prox = li;
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

TLista* retira(TLista* li, int i){
    TLista *p = li, *ant = NULL;
    while(p && p -> info != i){
        ant = p;
        p = p -> prox;
    }
    if (!p) return li;
    if(!ant) li = li -> prox;
    else ant -> prox = p -> prox;
    free(p);
    return li;
}

int verificaOrd(TLista* li){
    TLista *aux = li;
    if(!aux) return 1;
    while (aux->prox){
        if (aux -> info > (aux -> prox)-> info ) return 0;
        aux = aux -> prox;
    }
    return 1;
}

void ordena(TLista* li){
    if(!li) return;
    TLista *m = li,*n = li -> prox;
    int aux;
    while(n){
        if(m->info > n->info){
            aux = m ->info;
            m -> info = n -> info;
            n -> info = aux;
        }
        m = m -> prox;
        n = n -> prox;
    }
    imprime_lista(li);
    if (!verificaOrd(li)) ordena(li);
}

void imprime_lista(TLista* li){
    TLista* p;
    for (p = li; p != NULL; p = p->prox) printf("%d | ", p->info);
    printf("\n\n");
}

TLista* inverte1(TLista* li){
    TLista *aux = li, *novo = (TLista*) malloc(sizeof(TLista));
    while (aux){
        printf("%d", aux -> info);
        novo = insere_inicio(novo, aux -> info);
        TLista *auxfree = aux;
        aux = aux -> prox;
        free(auxfree);
    }
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
}
        tam--;
    }
}
