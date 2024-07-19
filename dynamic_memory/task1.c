#include <stdio.h>
#include <stdlib.h>


void main(){
   unsigned int n;
   unsigned int *numbers;

    scanf("%d", &n);

    numbers = malloc(n * sizeof(int));

    for(int i=0; i<n; i++)
    {
        numbers[i] = i+1;
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);

}