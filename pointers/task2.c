#include <stdio.h>

void main(){

    int a[100];
    int count = 0;

    scanf("%d", a + count);
    count++;
    
    while (*(a + count - 1) != 0)
    {
        scanf("%d", (a + count));
        count++;
    }
    
    count = 0;

    while (*(a + count) != 0)
    {
        printf("%d ", *(a + count));
        count++;
    }
    printf("\n");
    

}