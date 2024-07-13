#include <stdio.h>

unsigned int max_el(int numbers[], unsigned char length)
{
    int max_num = numbers[0];

    for(int i=1; i<length; i++)
    {
        if(max_num < numbers[i]) max_num = numbers[i];
    }

    return max_num;
}

void main(){
    int numbers[10];
    unsigned char length;

    scanf("%hhu", &length);
    for(int i=0; i<length; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("%u\n", max_el(numbers, length));

}