#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char grade_want;
    double grade_need, grade_current, grade_percentage;

    printf("Enter desired grade> ");
    scanf(" %c", &grade_want);
    printf("Enter minimum average required> ");
    scanf(" %lf", &grade_need);
    printf("Enter current average in course> ");
    scanf(" %lf", &grade_current);
    printf("Enter how much the final counts as a percentage of the course grade> ");
    scanf(" %lf", &grade_percentage);

    printf("You need a score of %.2lf on the final to get a %c.\n", 100 * (grade_need - grade_current) / grade_percentage + grade_current, grade_want);

    system("pause");

    return(0);
}

/*
    Write a program that predicts the score needed on a final exam to achieve a desired garde in a course.
    The program should interact with the user as follows:

        Enter desired grade> B
        Enter minimum average required> 79.5
        Enter current average in course> 74.6
        Enter how much the final counts as a percentage of the course grade> 25

        You need a score of 94.20 on the final to get a B.

In the example shown, the final counts 25% of the course grade.
*/