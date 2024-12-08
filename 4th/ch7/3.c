#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int fget_point_mass(FILE* input_file, int max_n, int locations[][10], int mass_vector[]);
double* center_grav(int locations[][10], int mass_vector[], int n);
void fwrite_point_mass(FILE* output_file, int locations[][10], int mass_vector[], int n);

int main()
{
    FILE *file_input, *file_output;
    int locations[3][10], mass_vector[10];
    int n;
    double* gravity_center;

    file_input = fopen("Input.txt", "r");
    file_output = fopen("Output.txt", "w");
    
    n = fget_point_mass(file_input, 10, locations, mass_vector);
    
    printf("location %2d %2d %2d\n", locations[0][0], locations[1][0], locations[2][0]);
    for (int i = 1; i < n; ++i)
        printf("         %2d %2d %2d\n", locations[0][i], locations[1][i], locations[2][i]);
    printf("mass     %d\n", mass_vector[0]);
    for (int i = 1; i < n; ++i)
        printf("         %d\n", mass_vector[i]);
    printf("n        %d\n", n);

    gravity_center = center_grav(locations, mass_vector, n);
    printf("grav center = (");
    printf("%.2lf,", gravity_center[0]);
    printf("%.2lf,", gravity_center[1]);
    printf("%.2lf", gravity_center[2]);
    printf(")");
   
    fwrite_point_mass(file_output, locations, mass_vector, n);

    fclose(file_input);
    fclose(file_output);

    system("pause");

    return(0);
}

int fget_point_mass(FILE *input_file, int max_n, int locations[][10], int mass_vector[10])
{
    int input_num, n;

    fscanf(input_file, "%d", &input_num);
    if (3 > input_num && input_num > max_n){
        printf("n value not allowed");
        return;
    }
    n = input_num;

    for (int i = 0; fscanf(input_file, "%d", &input_num) != -1; ++i) {
        if (i % 4 != 3)
            locations[i % 4][i / 4] = input_num;
        else
            mass_vector[i / 4] = input_num;
    }

    return(n);
    /*
        Takes an open input file and a maximum value for n as parameters 
        and fills a two-dimensional array output parameter with a location matrix 
        and a one-dimensional array output parameter with a mass vector from the data file.
        Returns as function value the actual value of n.
    */
}

double* center_grav(int locations[][10], int mass_vector[], int n)
{
    double grav_center[3] = {0, 0, 0};
    int total_mass = 0;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            grav_center[j] += locations[j][i] * mass_vector[i];
    for (int i = 0; i < 4; ++i)
        total_mass += mass_vector[i];
    for (int i = 0; i < 3; ++i)
        grav_center[i] /= total_mass;

    return (grav_center);

    /*
        Takes a location martix, mass vector, and n value as parameters, and calculates and returns as the function
        vaule the center of gravity of the system.
    */
}
//1.3 -0.9 0 / 10

void fwrite_point_mass(FILE *output_file, int locations[][10], int mass_vector[], int n)
{
    printf("hi");
    fprintf(output_file, "location %2d %2d %2d\n", locations[0][0], locations[1][0], locations[2][0]);
    for (int i = 1; i < n; ++i)
        fprintf(output_file, "         %2d %2d %2d\n", locations[0][i], locations[1][i], locations[2][i]);

    fprintf(output_file, "mass     %d\n", mass_vector[0]);
    for (int i = 1; i < n; ++i)
        fprintf(output_file, "         %d\n", mass_vector[i]);

    fprintf(output_file, "n        %d", n);

    /*
        Takes an open output file and the location matrix, mass vector, and n value of a point-mass system as parameters
        and writes the system to the file with meaningful labels.
    */
}

/*
    A point mass consists of a 3-D locatino and an associated mass, such as 
        Location: (6, 0, -2) Mass: 3g
    In a system of point masses, let p1, p2, ... pn be the n 3-D points and m1, m2, ... mn be their associated masses.
    If m is the sum of the masses, the center of gravity C is calculated as
        C = (m1p1 + m2p2 + ... + mnpn) / m
    Write a program that repeatedly inputs point-mass system data sets from an input file until an input operatin fails. 
    For each data set, display the location matrix, the mass vector, n, and the center of gravity.
    Each data set includes a location matrix (a matrix in which each row is point), a one-dimensional array of masses,
    and the number of point masses, n.
    Allow n to vary from 3 to 10
        Sample Data File
         4     
         5 -4  3  2
         4  3 -2  5
        -4 -3 -1  2
        -9  8  6  1
    This sample should be stored as:
        location  5 -4  3
                  4  3 -2
                 -4 -3 -1
                 -9  8  6
        mass     2
                 5
                 2
                 1
        n        4
    Your main function should repeatedly input and process data sets from an input file until end of file is encountered.
    For each point-mass system data set, display the location matrix, the mass vector, n, and the center of gravity.
    Implement at least the following functions:
        fget_point_mass:
            Takes an open input file and a maximum value for n as parameters 
            and fills a two-dimensional array output parameter with a location matrix and a one-dimensional array output parameter
            with a mass vector from the data file.
            Returns as function value the actual value of n.
        center_grav: 
            Takes a location martix, mass vector, and n value as parameters, and calculates and returns as the function
            vaule the center of gravity of the system.
        fwrite_point_mass:
            Takes an open output file and the location matrix, mass vector, and n value of a point-mass system as parameters
            and writes the system to the file with meaningful labels.
*/