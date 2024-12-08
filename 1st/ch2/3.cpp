#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int
main()
{
    double elpsed_H, elpsed_M, t, T;

    printf("How long have been since the power failure? (hours minutes)=> ");
    scanf(" %lf %lf", &elpsed_H, &elpsed_M);

    t = elpsed_H  + elpsed_M / 60;
    T = ((4 * t * t) / (t + 2)) - 20;

    printf("Estimated current freezer temperture => %lf\n", T);

    system("pause");

    return(0);
}

/*
    Write a program that estimates the temperture in a freezer (in ¢XC) given the elapsed time (hours) since a power failure.
    Assume this temperature (T) is given by
        T = ((4 * t^2) / (t + 2)) - 20
    where t is the time since power failure.
    Your program should prompt the user to enter how long it has been since the start of the power failure in whole hours and minutes.
    Note that you will need to convert the elapsed time into hours.
    For example, if the user entered 2 30 (2 hours 30 minutes), you would need to convert this to 2.5 hours.
*/