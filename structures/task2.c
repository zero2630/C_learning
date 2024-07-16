#include <stdio.h>

struct student
{
    char name[50];
    unsigned char age;
    unsigned char marks[10];
};

void insert_sort_max(unsigned char *numbers, unsigned char length)
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

    insert_sort_max(numbers, length);

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