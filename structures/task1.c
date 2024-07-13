#include <stdio.h>

struct student
{
    char name[50];
    unsigned char age;
    unsigned char marks[10];
    double average;
    unsigned char has_fails;
};

double find_average(unsigned char marks[], unsigned length, unsigned char *has_fails)
{
    double sum = 0;
    for(int i=0; i<length; i++)
    {
        if(marks[i]==2) *has_fails = 1;
        sum += marks[i];
    }
    return sum / length;
}


void best_student(struct student students[], unsigned length)
{
    struct student best;
    double best_average = 0;
    for(int i=0; i<length; i++)
    {
        if(!students[i].has_fails && students[i].average > best_average)
        {
            best = students[i];
            best_average = students[i].average;
        }
    }

    if(best_average != 0)
    {
        for(int i=0; best.name[i] != 0; i++)
        {
            printf("%c", best.name[i]);
        }
        printf(", %hhu лет, средний балл: %lf\n", best.age, best.average);
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
        students[i].has_fails = 0;
        students[i].average = find_average(students[i].marks, k, &(students[i].has_fails));
    }

    best_student(students, n);

}