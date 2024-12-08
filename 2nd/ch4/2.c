#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double wt_lb, ht_in, BMI;

    printf("Enter the weight (lb) => ");
    scanf(" %lf", &wt_lb);
    printf("Enter the height (in) => ");
    scanf(" %lf", &ht_in);

    BMI = (703 * wt_lb) / (ht_in * ht_in);
    printf("BMI = %.2lf \n", BMI);

    printf("Weight Status: ");
    if (BMI >= 30)
        printf("Obese");
    else if (30 > BMI && BMI >= 25)
        printf("Overweight");
    else if (25 > BMI && BMI >= 18.5)
        printf("Normal");
    else if (18.5 > BMI)
        printf("Underweight");
    printf("\n");

    system("pause");

    return(0);
}

/*
    Write a program that calculates the user's body mass index (BMI) and categorizes it as underweight,
    normal, overweight, or obese, based on the following table from the United States Centers for Disease Control:
        BMI            Weight Status
        Below 18.5     Underweight
        18.5-24.9      Normal
        25.0-29.9      Overweight
        30.0 and above Obese
    To calculate BMI based on weight in pounds (wt_lb) and height in inches (ht_in), use this formula (rounded to tenths):
        703 * wt_lb / ht_in * ht_in
    Prompt the user to enter weight in pounds and height in inches.
*/