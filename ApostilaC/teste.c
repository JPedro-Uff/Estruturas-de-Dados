#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *v;
    v = malloc(5);
    v[0] = 1;
    printf("%ld %d", sizeof(v), v[0]);
}