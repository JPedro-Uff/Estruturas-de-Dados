#include "ArvBin.h"

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
    printf("%d", calculaFilhos(arvTest));
}