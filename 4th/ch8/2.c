#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char COLOR_CODES[10][7] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white" };
    char color_input[3][7];
    double digits[3];

    printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end.\n");
    printf("Type the colors in lowercase letters only, NO CAPS.\n\n");

    while (1)
    {
        for (int i = 0; i < 3; ++i) {
            printf("Band %d => ", i + 1);
            gets(color_input[i]);
            digits[i] = search(COLOR_CODES, 10, color_input[i]);
        }
        for (int i = 0; i < 3; ++i)
            if (digits[i] == -1) {
                printf("Invalid color: %s\n", color_input[i]);
                goto end;
            }
        
        printf("Resistance value: %.2lf kilo-ohms\n", (digits[0] * 10 + digits[1]) * pow(10, digits[2]) / 1000);

        end: printf("Do you want to decode another resistor?\n=> ");
        if (getchar() == 'y') {
            printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end.\n");
            printf("Type the colors in lowercase letters only, NO CAPS.\n");
            getchar();
        }
        else
            break;
    } 

    system("pause");

    return(0);
}

int search(char colors[][7], int list_size, char target_string[])
{
    for (int i = 0; i < list_size; ++i)
        if (strcmp(colors[i], target_string) == 0)
            return(i);
    return(-1);
}

/*
    A resistor is a circuit device designed to have a specific resistance value between its ends.
    Resistance values are expressed in ohms (£[) or kilo-ohms (k£[).
    Resistors are frequently marked with colored bands that encode their resistance values, as shown in Fig. 8.23.
    The first two bands are digits, and the third is a power-of-ten multiplier.
    The table below shows the meanings of each band color.
    For example, if the first band is green, the second is black, and the third is orange, 
    the resistor has value of 50 ¡Ñ 10 ^ 3 or 50 k£[.
    The information in the table can be stored in a C program as an array of strings.
        char COLOR_CODES[10][7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
    Notice that "red" is COLOR_CODES[2] and has a digit value of 2 and a multiplier value of 10 ^ 2.
    In general, COLOR_CODES[n] has digit value n and multiplier value 10n.

    Write a program that prompts for the colors of Band 1, band 2, and Band 3, and then displays the resistance in kilo-ohms.
    Include a helper function search that takes three parameters--the list of strings, the size of the list, and a target string, 
    and returns the subscript of the list element that matches the target or returns -1 if the target is not in the list.
    Here is a short sample run:
        Enter the colors of the resistor's three bands, beginning with the band nearest the end.
        Type the colors in lowercase letters only, NO CAPS.

        Band 1 => green
        Band 2 => black
        Band 3 => yellow
        Resistance value: 500 kilo-ohms
        Doyou want tot decode another resistor?
        => y
        Enter the colors of the resistor's three bands, beginning with the band nearest the end.
        Type the colors in lowercase letters only, NO CAPS.
        Band 1 => brown
        Band 2 => vilet
        Band 3 => gray
        Invalid color: vilet
        Doyou want tot decode another resistor?
        => n
*/