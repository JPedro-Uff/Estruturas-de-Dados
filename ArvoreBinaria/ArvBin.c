#include "ArvBin.h"

TAB *criaRaiz(int i){
    TAB *novo = (TAB*) malloc (sizeof(TAB));
    novo -> chave = i;
    novo -> esq = NULL;
    novo -> dir = NULL;
    return novo;
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


TAB *insereOrd(TAB* no, int i){
    if(!no) return criaRaiz(i);
    else if(i < no->chave) no -> esq = insereOrd(no->esq, i);
    else if(i > no->chave) no -> dir = insereOrd(no->dir, i);
    return no;
}

TAB *busca(TAB* no, int i){
    if(no == NULL || no->chave == i) return no;
    else if(no->chave > i) return busca(no->esq, i);
    else return busca(no->dir, i);
}

TAB *copia(TAB* no){
    TAB *novo = criaRaiz(no->chave);
    if(no->esq) novo -> esq = copia(no->esq);
    if(no->dir) novo -> dir = copia(no->dir);
    return novo;
}

TAB *espelho(TAB* no){
    TAB *novo = criaRaiz(no->chave);
    if(no->dir) novo -> esq = espelho(no->dir);
    if(no->esq) novo -> dir = espelho(no->esq);
    return novo;
}

int maiorInt(TAB* raiz){
    if(raiz) maiorAux(raiz, raiz -> chave);
    else return 0;
}

int maiorAux(TAB* no, int n){
    if(no){
        if (no->chave > n) n = no -> chave;
        if(no->esq)n = maiorAux(no -> esq, n);
        if(no->dir)n = maiorAux(no -> dir, n);
    }
    else return 0;
    return n;
}

TAB* maiorNo(TAB* no){
    if(no->dir)no = no->dir;
    else return no;
}

int zz(TAB *no){
    if(no){
        if(no->esq && no->dir) return 0;
        else if(no->dir) zz(no->dir);
        else if(no->esq) zz(no->esq);
        else return 1;
    }
    printf("Arvore vazia");
    return 0;
}

TAB *exclui(TAB* no, int n){
    if (no == NULL) return no;
    else if(n < no->chave) no -> esq = exclui(no->esq, n);
    else if(n > no->chave) no -> dir = exclui(no->dir, n);

    else{
        if(!no->esq){
            TAB *temp = no->dir;
            free(no);
            return temp;
        }

        if(!no->dir){
            TAB *temp = no->esq;
            free(no);
            return temp;
        }
        
        TAB *maiorEsq = maiorNo(no->esq);
        no->chave = maiorEsq->chave;
        exclui(no->esq, maiorEsq->chave);
    }
    return no;
}

TAB *excluiPares(TAB *no){
    if(no){
        if(no->esq)no->esq = excluiPares(no->esq);
        if(no->dir)no->dir = excluiPares(no->dir);
        if(no->chave % 2 == 0)no = exclui(no,no->chave);
    }
    return no;
}

// TLista *ancestrais(TAB* no, int elem){
//     if(!busca(no, elem)) return NULL;
//     TLista *ListaAnc = cria_lista();
//     if(no){
//         if(elem < no ->chave) {
//             ListaAnc = insere_fim(ListaAnc, no->chave);
//             ListaAnc ->prox = ancestrais(no ->esq, elem);
//         }

//         else if(elem > no ->chave) {
//             ListaAnc = insere_fim(ListaAnc, no->chave);
//             ListaAnc ->prox = ancestrais(no ->dir, elem);
//         }

//         else if(elem == no ->chave) return ListaAnc;
//     }
//     return ListaAnc;
// }

// TLista *menores(TAB *no, int n){
//     TLista *ListaMen = cria_lista();
//     if(no){
//         if(no->chave < n) ListaMen = insere_fim(ListaMen, no ->chave);
//         else ListaMen = insere_fim(ListaMen, -1);

//         if(no ->dir) ListaMen ->prox = menores(no->dir, n);
//         if(ListaMen ->prox && no ->esq) ListaMen ->prox ->prox = menores(no->esq, n);
//         else if(no ->esq) ListaMen ->prox = menores(no->esq, n);
//         return ListaMen;
//     }
// }



int calculaFilhos(TAB *no){
    int n;
    if(no){
        if(no ->dir && no ->esq) n = calculaFilhos(no ->dir) + calculaFilhos(no ->esq);
        else if(no ->dir) n = calculaFilhos(no ->dir);
        else if(no ->esq) n = calculaFilhos(no ->esq);
        else return 1;
    }   
    return n + 1;
}