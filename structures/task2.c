#include <stdio.h>

struct student
{
    char name[50];
    unsigned char age;
    unsigned char marks[10];
};

void sort_max(unsigned char *numbers, unsigned char length)
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

double find_average(unsigned char numbers[], unsigned length)
{
    double sum = 0;
    for(int i=0; i<length; i++)
    {
        sum += numbers[i];
    }
    return sum / length;
}

void subject_info(struct student students[], unsigned subject_num, unsigned length)
{
    unsigned char numbers[length];

    for(int i=0; i<length; i++)
    {
        numbers[i] = students[i].marks[subject_num];
    }

    sort_max(numbers, length);

    printf("Предмет № %u:\nСредний балл студентов: %lf\n", subject_num+1, find_average(numbers, length));

    if(length%2 == 0) printf("Медианное значение оценок студентов: %hhu\n", numbers[length/2]);
    else printf("Медианное значение оценок студентов: %hhu\n", numbers[length/2+1]);

}

void main(){
    unsigned n, k, r;
    struct student students[30];

    scanf("%u %u %u", &n, &k, &r);

    for(int i=0; i<n; i++)
    {
        scanf("%s %hhu", students[i].name, &students[i].age);
        for(int j=0; j<k; j++)
        {
            scanf("%hhu", &students[i].marks[j]);
        }
    }

    for(int i=0; i<r; i++)
    {
        subject_info(students, i, n);
    }

}