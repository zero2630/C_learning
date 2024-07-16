#include <stdio.h>

struct student
{
    char name[50];
    unsigned char age;
    unsigned char marks[10];
};

double find_average(unsigned char marks[], unsigned length)
{
    double sum = 0;
    for(int i=0; i<length; i++)
    {
        if(marks[i]==2) return 0;
        sum += marks[i];
    }
    return sum / length;
}


void best_student(struct student students[], unsigned length, unsigned marks_length)
{
    struct student best;
    double best_average = 0, average;
    for(int i=0; i<length; i++)
    {
        average = find_average(students[i].marks, marks_length);
        if(average > best_average)
        {
            best = students[i];
            best_average = average;
        }
    }

    if(best_average != 0)
    {
        for(int i=0; best.name[i] != 0; i++)
        {
            printf("%c", best.name[i]);
        }
        printf(", %hhu лет, средний балл: %lf\n", best.age, best_average);
    }
    else printf("Таких студентов нет");
}

void main(){
    unsigned n, k;
    struct student students[30];

    scanf("%u %u", &n, &k);

    for(int i=0; i<n; i++)
    {
        scanf("%s %hhu", students[i].name, &students[i].age);
        for(int j=0; j<k; j++)
        {
            scanf("%hhu", &students[i].marks[j]);
        }
    }

    best_student(students, n, k);

}