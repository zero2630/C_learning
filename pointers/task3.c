#include <stdio.h>
#include <stdlib.h>

void main(){

    char *p = malloc(1024);
    int counter = 0;
    scanf("%[^\n]", p);

    while (*p != 0)
    {
        counter++;
        p++;
    }
    
    printf("%d\n", counter);
    
}