#include <stdlib.h>
#include <stdio.h>

typedef struct viz{
    int no_viz;
    struct viz *prox_viz;
}TV;

typedef struct grafo{
    int no;
    struct grafo *prox;
    TV *prim;
}TG;

TG *busca_vertice(TG* g, int v1){
    while(g && g->no!=v1)g = g->prox;
    return g;
}

TV *busca_aresta(TG* g, int v1, int v2){
    TG *rv1 = busca_vertice(g, v1);
    TG *rv2 = busca_vertice(g, v2);
    TV *resp = rv1 ->prim;
    while(resp && resp->no_viz!=v2) resp = resp ->prox_viz;
    return resp;
}

void imprime(TG *g){
    if(g){
        printf("Vertice: %d\n", g->no);
        printf("Vizinhos: ");
        TV *v = g->prim;
        while(v){
            printf("%d ", v->no_viz);
            v = v->prox_viz;
        }
        printf("\n\n");
        imprime(g->prox);
    }
}

TG *insere_vertice(TG *g, int n){
    TG *novo = (TG*) malloc(sizeof(TG));
    novo ->no = n;
    novo ->prim = NULL;
    novo ->prox = g;
    return novo;
}

void insere_direcional(TG* g, int v1, int v2){
    TG *rv1 = busca_vertice(g,v1);
    TV *novo = (TV*) malloc(sizeof(TV));
    novo ->no_viz = v2;
    novo ->prox_viz = rv1 ->prim;
    rv1 ->prim = novo;
}

void insere_aresta(TG* g, int v1, int v2){
    insere_direcional(g, v1, v2);
    insere_direcional(g, v2, v1);
}

void retira_direcional(TG* g, int v1, int v2){
    TG *busca = busca_vertice(g, v1);
    if(busca){
        TV *ant = NULL, *atual = busca ->prim;
        while(atual && atual ->no_viz != v2){
            ant = atual;
            atual = atual ->prox_viz;
        }
        if (ant = NULL) busca ->prim = atual;
        else ant ->prox_viz = atual ->prox_viz;
        free(atual);
    }

}

void retira_aresta(TG* g, int v1, int v2){
    retira_direcional(g, v1, v2);
    retira_direcional(g, v1, v2);
}

void retira_vertice(TG *g, int v){
    TG *aux = g, *ant = NULL;
    while(aux && aux ->no != v){
        ant = aux;
        aux = aux ->prox;
    }
    if(aux){
        while(aux ->prim) retira_aresta(g, v, aux ->prim ->no_viz);
        if(!ant) g = g ->prox;
        else ant ->prox = aux ->prox;
        free(aux);
    }
}

int main(void){
    TG *g = NULL;
    int n = 0;
    scanf("%d", &n);
    while (n >= 0){
        g = insere_vertice(g, n);
        imprime(g);
        scanf("%d", &n);
    }
    
    n = 0;
    int n2 = 0;

    while (n >= 0){
        scanf("%d", &n);
        scanf("%d", &n2);
        insere_aresta(g, n, n2);
        imprime(g);
    }
    

}