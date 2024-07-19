#include <stdio.h>
#include <stdlib.h>


void insert_sort_max(unsigned char *numbers, unsigned int length)
{
    unsigned char current_val;
    int location;

    for(int i=1; i<length; i++)
    {
        current_val = numbers[i];
        location = i-1;

        while (location > 0 && numbers[location] > current_val)
        {
            numbers[location+1] = numbers[location];
            location--;
        }
        if(location == 0 && numbers[location] > current_val) numbers[location+1] = numbers[location];
        numbers[location] = current_val;
        
    }

}

void main(){
   unsigned int n;
   unsigned char *numbers;

    scanf("%d", &n);

    numbers = malloc(n*n*sizeof(int));
    for(int i=0; i<n*n; i++)
    {
        numbers[i] = rand()%9+1;
    }

    printf("изначальная матрица:\n");
    for(int i=0; i<n*n; i++)
    {
        printf("%d ", numbers[i]);
        if((i+1)%n==0) printf("\n");
    }
    printf("\n");

    insert_sort_max(numbers, n*n);

    printf("отсортированная матрица:\n");
    for(int i=0; i<n*n; i++)
    {
        printf("%d ", numbers[i]);
        if((i+1)%n==0) printf("\n");
    }
    printf("\n");

    free(numbers);

}