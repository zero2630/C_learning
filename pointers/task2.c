#include <stdio.h>

void main(){

    int a[100];
    int *p = a;
    int num;

    do
    {
        scanf("%d", &num);
        *p = num;
        p++;
    } while (num != 0);

    p = a;

    do
    {
        printf("%d ", *p);
        p++;
    } while (*p != 0);
    

}