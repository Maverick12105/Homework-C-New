#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* Stat;
    char fInput;
    int player_number;
    double batting_denominator, batting_numerator;

    Stat = fopen("Stat.txt", "r");

    while (fscanf(Stat, "%c", &fInput) == 1) //printf("%c", fInput);
    {
        player_number = 0;
        batting_denominator = 0;    //reset every row
        batting_numerator = 0;

        while (fInput != ' ')                                     //reading player number in char
        {                                                         //and turning it into int
            player_number = player_number * 10 + fInput - '0';    //by moving previous numbers to the left by one digit
            fscanf(Stat, "%c", &fInput);                          //and adding the current digit
        }                                                         //lastly, after finish reading the numbers, read the next char
        printf("Player %d's record: ", player_number);            //which should be a space, thus exiting the loop
        while (fInput != '\n')
        {
            fscanf(Stat, "%c", &fInput);    //read the next char first, skipping the space
            printf("%c", fInput);   //printing the char as it read
            switch (fInput)
            {
            case 'H':
                ++batting_numerator;
                ++batting_denominator;  //only Hits and Outs count
                break;
            case 'O':
                ++batting_denominator;
                break;
            }
        }   //print \n from the file
        printf("Player %d's batting average: %.3lf\n\n", player_number, batting_numerator / batting_denominator);
    }

    fclose(Stat);

    system("pause");

    return(0);
}

/*
    A baseball player's batting average is calculated as the number of hits divided by the official number of at-bats.
    In calculating official at-bats, walks, sacrifices, and occasions when hit by the pitch are not counted.
    Write a program that takes an input file containing player numbers and batting records.
    Trips to the plate are coded in the batting record as follows:
        H -- hit, 
        O -- out,
        W -- walk,
        S -- sacrificec, 
        P -- hit by pitch.
    The program should output for each player the input data followed by the batting average.
    (Hint: Each batting record is followed by a newline character.)
    Sample input file:
        12 HOOOWSHHOOHPWWHO
        4 OSOHHHWWOHOHOOO
        7 WPOHOOHWOHHOWOO
    Corresponding output:
        Player 12's record: HOOOWSHHOOHPWWHO (5 6 3 1 1
        Player 12's batting average: 0.455

        Player 4's record: OSOHHHWWOHOHOOO (5 7 2 1 0
        Player 4's batting average: 0.417

        Player 7's record: WPOHOOHWOHHOWOO (4 7 3 0 1
        Player 7's batting average: 0.364
*/