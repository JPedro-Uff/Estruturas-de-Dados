#include <stdio.h>
#include <string.h>

void ex41(){
    int a = 1;
    char b = 'a';
    double c = 1.1;

    printf("%d\n", a);
    printf("%c\n", b);
    printf("%f\n", c);
}

void ex42(){
    int a = 0xA;
    int o = 010;

    printf("%#X\n", a);
    printf("%#o\n", o);
    printf("%d %d", a, o);
}

void ex43(){
    int I;

    scanf("%d", &I);
    printf("%#X\n", I);
    printf("%#o\n", I);
}

void ex44(){
    double r;

    scanf("%lf", &r);
    printf("%.1lf", r);
}

void ex45(){
    char p1[10], p2[10], p3[10];

    scanf("%s\n%s\n%s", p1, p2, p3);
    printf("%8s\n %8s\n %8s\n", p1, p2, p3);
}

void ex46(){
    
}

int main(void){
    ex45();
    return 0;
}
