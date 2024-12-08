#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int within_x_percent(double ref, double data, double percentage);

int main()
{
    double temp;

    printf("observed boiling point of a substance (¢XC) => ");
    scanf(" %lf", &temp);

    if (within_x_percent(100, temp, 5) == 1)
        printf("Water\n");
    else if (within_x_percent(357, temp, 5) == 1)
        printf("Mercury\n");
    else if (within_x_percent(1187, temp, 5) == 1)
        printf("Copper\n");
    else if (within_x_percent(2193, temp, 5) == 1)
        printf("Silver\n");
    else if (within_x_percent(2660, temp, 5) == 1)
        printf("Gold\n");
    else
        printf("Substance unknown\n");

    system("pause");

    return(0);
}
int within_x_percent(double ref, double data, double percentage)
{
    if (ref * (1 - percentage / 100) <= data && data <= ref * (1 + percentage / 100))
        return(1);
    else
        return(0);
}

/*
    The table below shows the normal boiling points of several substances.
    Write a program that prompts the user for the observed boiling point of a substance in ¢XC and identifies the sbstance if 
    the observed boiling point is within 5% of the expected boiling point.
    If the data input is more than 5% higher or lower than any of the boiling points in the table,
    the program should output the message Substance unknown.
        Substance Normal Boiling Point(¢XC)
        Water     100
        Mercury   357
        Copper    1187
        Silver    2193
        Gold      2660
    Your program should define and call a function within_x_percent that takes as parameters a reference value ref,
    a data value data, and a percentage value x and returns 1 meaning true if data is within x% of ref---that is, 
    (ref - x% * ref) <= data <= (ref + x% * ref).
    Otherwise within_x_percent would return zero, meaning false.
    For example, the call within_x_percent(357, 323, 10) would return true,
    since 10% of 357 is 35.7, and 323 falls between 321.3 and 392.7

*/