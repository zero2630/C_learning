#include <stdio.h>

void sort_max(int *numbers, unsigned char length)
{
    char is_sorted = 0;

    while(!is_sorted)
    {
        is_sorted = 1;
        for(int i=1; i<length; i++)
        {
            if(numbers[i]<numbers[i-1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = temp;
                is_sorted = 0;
            }
        }
    }
}

void sort_min(int *numbers, unsigned char length)
{
    char is_sorted = 0;

    while(!is_sorted)
    {
        is_sorted = 1;
        for(int i=1; i<length; i++)
        {
            if(numbers[i]>numbers[i-1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = temp;
                is_sorted = 0;
            }
        }
    }
}

void main(){
    int numbers[10];
    unsigned char length;
    unsigned char action;
    void (*selected)(int*, unsigned char);

    scanf("%hhu", &length);
    for(int i=0; i<length; i++)
    {
        scanf("%d", &numbers[i]);
    }
    scanf("%hhu", &action);

    switch (action)
    {
    case 1:
        selected = sort_max;
        break;

    case 2:
        selected = sort_min;
        break;
    
    default:
        break;
    }

    selected(numbers, length);

    for(int i=0; i<length; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

}