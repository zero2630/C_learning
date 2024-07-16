#include <stdio.h>

void insert_sort_max(int *numbers, unsigned char length)
{
    int location, current_val;

    for(int i=1; i<length; i++)
    {
        current_val = numbers[i];
        location = i-1;

        while (location >= 0 && numbers[location] > current_val)
        {
            numbers[location+1] = numbers[location];
            location--;
        }
        numbers[location+1] = current_val;
        
    }

}

void insert_sort_min(int *numbers, unsigned char length)
{
    int location, current_val;

    for(int i=1; i<length; i++)
    {
        current_val = numbers[i];
        location = i-1;

        while (location >= 0 && numbers[location] < current_val)
        {
            numbers[location+1] = numbers[location];
            location--;
        }
        numbers[location+1] = current_val;
        
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
        selected = insert_sort_max;
        break;

    case 2:
        selected = insert_sort_min;
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