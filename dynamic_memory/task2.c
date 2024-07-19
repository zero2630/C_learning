#include <stdio.h>
#include <stdlib.h>


void main(){
   unsigned int n, h, w, stop_h, stop_w;
   unsigned int **numbers;
   unsigned char is_left=0, is_right=1, is_up=0, is_down=0;

    scanf("%d", &n);

    numbers = calloc(n*n, sizeof(int));
    for(int i=0; i<n; i++)
    {
        numbers[i] = calloc(n, sizeof(int));
    }
    h = n-1;
    w = 0;
    stop_h = n-1;
    stop_w = n-1;


    for(int i=0; i<n*n; i++)
    {
        if(is_right && w < stop_w)
        {
            numbers[h][w] = i+1;
            w++;
        }
        else if(is_right && w == stop_w)
        {
            is_right = 0;
            is_up = 1;
            numbers[h][w] = i+1;
            h--;
        }

        else if(is_up && h > n-stop_h-1)
        {
            numbers[h][w] = i+1;
            h--;
        }
        else if(is_up && h == n-stop_h-1)
        {
            is_up = 0;
            is_left = 1;
            stop_h--;
            numbers[h][w] = i+1;
            w--;
        }

        else if(is_left && w > n-stop_w-1)
        {
            numbers[h][w] = i+1;
            w--;
        }
        else if(is_left && w == n-stop_w-1)
        {
            is_left = 0;
            is_down = 1;
            stop_w--;
            numbers[h][w] = i+1;
            h++;
        }

        else if(is_down && h < stop_h)
        {
            numbers[h][w] = i+1;
            h++;
        }
        else if(is_down && h == stop_h)
        {
            is_down = 0;
            is_right = 1;
            numbers[h][w] = i+1;
            w++;
        }

    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) printf("%d ", numbers[i][j]);
        printf("\n");
        free(numbers[i]);
    }
    

    free(numbers);

}