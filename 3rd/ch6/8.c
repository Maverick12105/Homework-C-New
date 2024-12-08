#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void charges(double connection_time, double* total_charge, double* cost_per_hr);
double round_money(double input);

int main()
{
    FILE *file_data, *file_output;
    int clien_number, date_month, date_year;
    double time_used, charge_total, charge_per_hr;

    file_data = fopen("usage.txt", "r");
    file_output = fopen("charges.txt", "w");

    fscanf(file_data, "%d", &date_month);
    fscanf(file_data, "%d", &date_year);

    fprintf(file_output, "Charges for %d/%d", date_month, date_year);
    fprintf(file_output, "\n\nCustomer   Hours used   Charge per hour   Average cost");
    while (fscanf(file_data, "%d", &clien_number) == 1)
    {
        fprintf(file_output, "\n%-13d ", clien_number);
        fscanf(file_data, "%lf ", &time_used);
        charges(time_used, &charge_total, &charge_per_hr);
        fprintf(file_output, "%-14.1lf ", time_used);
        fprintf(file_output, "%-16.2lf ", charge_total);
        fprintf(file_output, "%.2lf", charge_per_hr);
    }

    fclose(file_data);
    fclose(file_output);

    system("pause");

    return(0);
}

void charges(double connection_time, double *total_charge, double *cost_per_hr)
{
    if (connection_time > 10)
        *total_charge = 7.99 + ceil(connection_time - 10) * 1.99;
    else
        *total_charge = 7.99;
    *cost_per_hr = round_money(*total_charge / connection_time);
}

double round_money(double input)
{
    return((int)(input * 100 + 0.5) * 0.01);
}

/*
    InternetLite Corporation is an Internet service provider 
    that charges customers a flat rate of $7.99 for up to 10 hours of connection time.
    Additional hours or partial hours are charged at $1.99 each.
    Write a function charges that computes the total charge for a customer based on the number of 
    hours of connection time used in a month.
    The function should also calculate the average cost per hour of the time used (rounded to the nearest cent),
    so use two output parameters to send back these results.
    Write a second function round_money that takes a real number as an input argument and returns as the function value the number
    rounded to two decimal places.
    Write a main function that takes data from an input file usage.txt and produces an output file charges.txt.
    The data file format is as follows:
        Line 1: current month and year as two integers
        Other lines: customer number (a five-digit number) and number of hours used
        Here is a sample data file and  the corresponding output file:

            Data file usage.txt
                10 2009
                15362 4.2
                42768 11.1
                11111 9.9

            Output file charges.txt
                Charges for 10/2009

                Customer   Hours used   Charge per hour   Average cost
                15362      4.2          7.99              1.90
                42768      11.1         11.97             1.08
                11111      9.9          7.99              0.81
*/