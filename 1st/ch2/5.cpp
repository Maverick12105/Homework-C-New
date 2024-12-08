#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int
main()
{
    int infuse_V, infuse_T;

    printf("Volume to be infused (ml) => ");
    scanf(" %d", &infuse_V);
    printf("Minutes over which to infuse => ");
    scanf(" %d", &infuse_T);

    printf("\n");
    printf("VTBI: %d ml\n", infuse_V);
    printf("Rate: %d ml/hr\n", infuse_V * 60 / infuse_T);

    system("pause");

    return(0);
}

/*
    Hospitals use programmable pumps to deliver medications and fluids to intravenous lines at a set number of milliliters per hour.
    Write a program to output information for the labels the hospital pharmacy places on bags of I.V. medications 
    indicating the volume of medication to be infused and the rate at which to pump should be set.
    The program should prompt the user to enter the quantity of fluid in the bag 
    and the number of minutes over which it should be infused.
    Output the VTBI (volume to be infused) in ml and the infusion rate in ml/hr.

    Sample run:
        Volume to be infused (ml) => 100
        Minutes over which to infuse => 20

        VTBI: 100 ml
        Rate: 300 ml/hr
*/