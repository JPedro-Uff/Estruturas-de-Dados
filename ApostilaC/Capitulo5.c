#include <stdio.h>
#include <math.h>

void ex54(){
    int a = 0, resultado;
    printf("\nTabela verdade OU EXCLUSIVO:\n\nA  B  C\n\n");
    while(a<=1){
        int b = 0;
        while(b<=1){
            if(a==0 && b==0) printf("%d  %d  0\n", a, b);
            else if(a==1 && b==0) printf("%d  %d  1\n", a, b);
            else if(a==0 && b==1) printf("%d  %d  1\n", a, b);
            else printf("%d  %d  0\n\n", a, b);
            b++;
        }
        a++;
    }
}

void ex55(){
    int x,n;
    scanf("%d", &x);
    scanf("%d", &n);
    int resultado = x * pow(2, n);
    printf("%d * 2 ^ %d = %d", x, n, resultado);
}

void ex57(){
    int segundos, minutos = 0, horas = 0;
    printf("Digite os segundos para conversão:\n");
    scanf("%d", &segundos);
    while(segundos >= 3600){
        horas++;
        segundos -= 3600;
    }
    while(segundos >= 60){
        minutos++;
        segundos -= 60;
    }
    printf("\n%d Horas, %d Minutos e %d Segundos\n", horas, minutos, segundos);
}

int main(void){
    ex57();
    return 0;
}