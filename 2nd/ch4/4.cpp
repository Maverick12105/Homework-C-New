#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char color;

    printf("cylinder color => ");
    scanf(" %c", &color);

    switch (color)
    {
    case 'O':
    case 'o':
        printf("Ammonia");
        break;
    case 'B':
    case 'b':
        printf("Carbon monoxide");
        break;
    case 'Y':
    case 'y':
        printf("Hydrogen");
        break;
    case 'G':
    case 'g':
        printf("Oxygen");
        break;
    default:
        printf("Contents unknown");
    }
    printf("\n");

    system("pause");

    return(0);
}

/*
    Write a program that reports the contents of a compressed-gas cylinder based on the first letter of the cylinder's color.
    The program input is a character representing the observed color of the cylinder:
    "Y" or "y" for yellow, "O" or "o" for orange, and so on.
    Cylinder colors and associated contents are as follows:
        orange ammonia
        brown  carbon monoxide
        yellow hydrogen
        green  oxygen
    Your program should repond to input of a letter other than the first letters of the given colors with the message, Contents unknown.
*/