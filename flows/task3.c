#include <stdio.h>
#include <stdlib.h>

struct car
{
    char name[10];
    char color[10];
    char number[6];
};

void save(struct car *structures, unsigned int n)
{
    FILE *fp = fopen("data.bin", "wb");

    char *p = (char *)&n;

    for(int i=0; i<sizeof(n); i++)
    {
        putc(*p, fp);
        p++;
    }

    p = (char *)structures;


    for(int i=0; i<(sizeof(struct car)*n); i++)
    {
        putc(*p, fp);
        p++;
    }

    fclose(fp);
}

void load()
{
    FILE *fp = fopen("data.bin", "rb");

    int *struct_count = malloc(sizeof(int));

    char *p = (char *)struct_count;

    for(int i=0; i<sizeof(int); i++)
    {
        *p = getc(fp);
        p++;
    }

    struct car *cars = malloc((*struct_count)*sizeof(struct car));
    p = (char*)cars;

    for(int i=0; i<((*struct_count)*sizeof(struct car)); i++)
    {
        *p = getc(fp);
        p++;
    }

    for(int i=0; i<*struct_count; i++)
    {
        printf("%s %s %s\n", cars[i].name, cars[i].color, cars[i].number);
    }

    fclose(fp);
}

int main()
{
    struct car *cars;
    unsigned int n;

    scanf("%u", &n);

    cars = malloc(n*sizeof(struct car));

    for(int i=0; i<n; i++)
    {
        scanf("%10s %10s %6s", cars[i].name, cars[i].color, cars[i].number);
    }

    save(cars, n);

    load();
    
    
    return 0;
}