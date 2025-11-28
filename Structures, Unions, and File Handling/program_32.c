// Write a C program to calculate the total and percentage marks of a student using array of structure.

#include <stdio.h>
#include <string.h>

int main()
{
    struct marks
    {
        char subject_name[10];
        int subject_marks;
        int maximum_marks;
    };

    struct student
    {
        char name[10];
        int rollNo;
        struct marks subject[5];
    };

    struct student student1;
    strcpy(student1.name, "danish");
    student1.rollNo = 2418;
    strcpy(student1.subject[0].subject_name, "Maths");
    student1.subject[0].subject_marks = 84;
    student1.subject[0].maximum_marks = 100;

    strcpy(student1.subject[1].subject_name, "physics");
    student1.subject[1].subject_marks = 78;
    student1.subject[1].maximum_marks = 100;

    strcpy(student1.subject[2].subject_name, "chemistry");
    student1.subject[2].subject_marks = 62;
    student1.subject[2].maximum_marks = 100;

    strcpy(student1.subject[3].subject_name, "English");
    student1.subject[3].subject_marks = 79;
    student1.subject[3].maximum_marks = 100;

    strcpy(student1.subject[4].subject_name, "socilogy");
    student1.subject[4].subject_marks = 86;
    student1.subject[4].maximum_marks = 100;

    int total_marks = 0;
    int total_maximum_marks = 0;
    for (int i = 0; i < 5; i++)
    {
        total_marks += student1.subject[i].subject_marks;
        total_maximum_marks += student1.subject[i].maximum_marks;
    }

    float percentage = ((float)total_marks / total_maximum_marks) * 100;
    printf("Total Marks: %d\n", total_marks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}