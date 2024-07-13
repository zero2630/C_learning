#include <stdio.h>

unsigned int num_sum(unsigned int number)
{
    unsigned int sum = 0;

    if(number%10 == 0) return number;

    return number%10 + num_sum(number / 10);
}

void main(){
    unsigned number;

    scanf("%u", &number);
    printf("%u\n", num_sum(112358));

}