#include "Lista.h"

int main(void){
    TLista *l = (TLista*) malloc (sizeof(TLista));
    int op;
    l = cria_lista();
    while (1){
        imprime_lista(l);
        printf("1 |Inserir no Inicio\n2 |Inserir no fim\n");
        printf("3 |Remover elemento\n4 |Ordenar Lista\n");
        printf("5 |Inverter a lista\n6 |Mostrar numero de elementos\n0 |Sair\n");
        printf("\nDigite a operacao desejada: ");
        scanf("%d", &op);
        system("clear");
        imprime_lista(l);
        if(op == 0) {
            system("clear");
            break;
        }
        switch (op){
            case (1):
                printf("Digite o numero a ser inserido no inicio:\n");
                int n1;
                scanf("%d", &n1);
                l = insere_inicio(l, n1);
                system("clear");
                break;
        
            case(2):
                printf("Digite o numero a ser inserido no fim:\n");
                int n2;
                scanf("%d", &n2);
                l = insere_fim(l, n2);
                system("clear");
                break;
            
            case(3):
                printf("Digite o numero a ser removido:\n");
                int n4;
                scanf("%d", &n4);
                l = retira(l, n4);
                system("clear");
                break;

            case(4):
                ordena(l);
                system("clear");
                break;

            case(5):
                inverte2(l);
                system("clear");
                break;

            case(6):
                system("clear");
                printf("A lista possui %.0f elementos\n" ,tamanho(l));
                break;

            default:
                system("clear");
                printf("Operador invalido.\n");
                break;
            }
    }
    
    printf("\n");
}