#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int num1, num2, num3;

    scanf("%d/%d/%d", &num1, &num2, &num3);

    if(num1>31||num2>12) printf("error\n");
    else printf("%u/%u/%u\n", num2, num1, num3);
    
    return 0;
}