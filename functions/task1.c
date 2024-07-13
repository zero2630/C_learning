#include <stdio.h>

void discount_calc(double start_cost, double discount, unsigned int times)
{
    double cost = start_cost;
     for(int i=0; i<times; i++)
     {
        cost *= (100 - discount) * 0.01;
     }
     
     printf("%lf\n", cost);

}

void main(){
   double cost, discount;
   unsigned times;

   scanf("%lf %lf %d", &cost, &discount, &times);

    discount_calc(cost, discount, times);

}