#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void flu_predict();

int main()
{
    printf("FLU EPIDEMIC PREDICTIONS BASED ON ELAPSED DAYS SINCE FIRST CASE REPORT\n");

    flu_predict();
    flu_predict();
    flu_predict();

    system("pause");

    return(0);
}

void flu_predict()
{
    double flu_days;

    printf("\nEnter day number>> ");
    scanf(" %lf", &flu_days);

    printf("By day %.0lf, model predicts %.0lf cases total.\n", flu_days, pow(40000 / (1 + 39999 * exp(-0.24681)), flu_days));
}

/*
    An epidemic of a new strain of flu (i.e., one for which a vaccine is not available) 
    begins with a single case on a college campus of 40000 faculty, staff and students.
    Three days later a second case is reported, and in the following days the reported cases are as shown in the table below.
    The day of the initial case report is noted as day 0.
        Day#        0 3 5 6 7 8 9 10 11
        Total cases 1 2 3 4 5 7 9 11 15
    A math professor observes that the number of cases seems to be increasing by about 28% per day
    and proposes the following model to predict the total number of cases by day number x:
        Cases(x) = 40000 / (1 + 39999(e ^ -0.24681))
        *(40000 / (1 + 39999(e ^ -0.24681))) ^ x
    Write a function that implements this model.
    Test your function with a main function that prompts the user three times to enter a day number 
    and then calculates and displays the number of cases predicted for each day number entered.

    Sample run:
        FLU EPIDEMIC PREDICTIONS BASED ON ELAPSED DAYS SINCE FIRST CASE REPORT
    
        Enter day number>> 7
        By day 7, model predicts 5 cases total.
    
        Enter day number>> 10
        By day 10, model predicts 11 cases total.
    
        Enter day number>> 20
        By day 20, model predicts 138 cases total.
*/