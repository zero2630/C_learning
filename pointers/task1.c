#include <stdio.h>

void main(){

    int a, b;
    int *ap = &a, *bp = &b;
    scanf("%d %d", &a, &b);
    printf("%d\n", *ap+*bp);

}