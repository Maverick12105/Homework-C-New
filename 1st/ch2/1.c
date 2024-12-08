#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int
main()
{
    double odometer_s, odometer_f;

    printf("TAXI FARE CALCULATOR\n");
    printf("Enter beginning odometer reading=> ");
    scanf(" %lf", &odometer_s);
    printf("Enter ending odometer reading=> ");
    scanf(" %lf", &odometer_f);

    printf("You traveled a distance of %.1lf miles. At $1.50 per mile, your fare is $%.2lf.\n", odometer_f - odometer_s, (odometer_f - odometer_s) * 1.5);

    system("pause");

    return(0);
}

/*
    Write a program that calculates taxi fare at a rate of $1.50 per mile.
    Your program should interact with the user in this manner:
        TAXI FARE CALCULATOR
        Enter beginning odometer reading=> 78602.5
        Enter ending odometer reading=> 78622.7
        You traveled a distance of 20.2 miles.
        At $1.50 per mile, your fare is $30.30.
*/