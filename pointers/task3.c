#include <stdio.h>
#include <stdlib.h>

void main(){

    char *p = malloc(1024);
    int counter = 0;
    scanf("%[^\n]", p);

    do
    {
        counter++;
        p++;
    } while (*p != 0);
    
    printf("%d\n", counter);
    
}