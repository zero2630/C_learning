#include <stdio.h>
#include <stdlib.h>

void main(){

    char *p1 = malloc(101), *p2 = malloc(51), *p1_cash = p1;
    int counter = 0;
    scanf("%[^\n]\n", p1);
    scanf("%[^\n]", p2);

    do
    {
        p1++;
    } while (*p1 != 0);

    do
    {
        *p1 = *p2;
        p1++;
        p2++;
    } while (*p2 != 0);

    p1 = p1_cash;
    
    do
    {
        printf("%c", *p1);
        p1++;
    } while (*p1 != 0);

    printf("\n");
    
}