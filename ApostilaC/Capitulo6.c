#include <stdio.h>
#include <math.h>

void ex63(){
    int n1, n2, operacao, resultado;
    printf("1-Multiplicar | 2-Somar | 3-Subtrair | 4-Dividir\n");
    scanf("%d", &operacao);
    printf("Digite os numeros: x y\n");
    scanf("%d %d", &n1, &n2);
    if (operacao == 1) resultado = n1 * n2;
    else if (operacao == 2) resultado = n1 + n2;
    else if (operacao == 3) resultado = n1 - n2;
    else if (operacao == 4) resultado = n1 / n2;
    else printf("Operacao invalida\n");
    printf("Resultado: %d\n", resultado);
}

int main(void){
    ex63();
}