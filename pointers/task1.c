#include <stdio.h>

void main(){

    int a, b;
    int *ap = &a, *bp = &b;
    scanf("%d %d", ap, bp);
    printf("%d\n", *ap+*bp);

}