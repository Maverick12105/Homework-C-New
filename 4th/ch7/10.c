#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void race_result(int data[][5]);
char candidate_determine(int candidate);

int main()
{
    int data[4][5] = {{192, 147, 186, 114, 267},
                       {48, 90, 12, 21, 13},
                       {206, 312, 121, 408, 382},
                       {37, 21, 38, 39, 29}};
    
    race_result(data);

    data[2][3] = 108;
    race_result(data);

    system("pause");

    return(0);
}

void race_result(int data[][5])
{
    int total_vote[4] = { 0, 0, 0, 0 };
    int highest = 0, higher = 0;
    
    printf("Precinct   Candidate A   Candidate B   Candidate C   Candidate D\n");
    for (int i = 0; i < 5; ++i) {
        printf("    %d          %3d            %2d           %3d            %2d\n", i + 1, data[0][i], data[1][i], data[2][i], data[3][i]);
        total_vote[0] += data[0][i];
        total_vote[1] += data[1][i];
        total_vote[2] += data[2][i];
        total_vote[3] += data[3][i];
    }

    printf("  Total        %3d           %3d           %3d          %3d\n", total_vote[0], total_vote[1], total_vote[2], total_vote[3]);

    for (int i = 0; i < 4; ++i) {
        if (total_vote[i] >= (total_vote[0] + total_vote[1] + total_vote[2] + total_vote[3]) / 2) {
            printf("Winner is Candidate %c\n", candidate_determine(i));
            return;
        }
        if (total_vote[i] > highest) {
            higher = highest;
            highest = i;
        }
    }
    printf("Runoff between %c and %c\n", candidate_determine(highest), candidate_determine(higher));
}

char candidate_determine(int candidate)
{
    switch (candidate)
    {
    case 0:
        return ('A');
    case 1:
        return ('B');
    case 2:
        return ('C');
    case 3:
        return ('D');
    }

}

/*
    The results from the mayor'r race have been reported by each precinct as follows:
        Precinct   Candidate A   Candidate B   Candidate C   Candidate D
            1          192            48           206            37
            2          147            90           312            21
            3          186            12           121            38
            4          114            21           408            39
            5          267            13           382            29
    Write a program to do  the following:
        a. Display the table with appropriate labels for the rows and columns.
        b. Compute and display the total number of botes receiced by each candidate and the percentage of the total votes cast.
        c. If any one candidate received over 50% of the votes, the program should display a message 
        declaring that candidate the winner.
        d. If no candidate received 50% of the votes, the program should display a message declaring a runoff between the
        two candidate should be identified by their letter names.
        e. Run the program once with the data shown and once with candidate C receiving only 108 votes in Precinct 4.
*/