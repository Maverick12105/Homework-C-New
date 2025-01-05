#define _CRT_NO_SECURE_WARNING

#include <stdio.h>
#include <stdlib.h>

void pathfind(char maze[8][8], int x, int y, char path[], int step);

int main()
{
    char maze[8][8] = {{' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ','X',' ','X','X',' ','X',' '},
                       {' ','X',' ','X','X',' ','X',' '},
                       {' ','X',' ',' ','X',' ','X',' '},
                       {' ','X','X','X','X',' ','X',' '},
                       {' ',' ',' ','X',' ',' ','X',' '},
                       {' ','X',' ','X','X','X','X',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' '}};

    char path[64];

    pathfind(maze, 0, 1, path, 0);

    system("pause");

    return(0);
}

void pathfind(char maze[8][8], int x, int y, char path[], int step)
{
    if (0 <= x && x <= 7 && 0 <= y && y <= 7 && maze[x][y] != 'X') {
        maze[x][y] = 'X';

        if (x == 7 && y == 7) {
            path[step] = '\0';
            for (int i = 0; path[i] != '\0'; ++i)
                printf("%c", path[i]);
            printf("\n");
        }
        else {
            path[step] = 'u';
            pathfind(maze, x, y + 1, path, step + 1);

            path[step] = 'l';
            pathfind(maze, x - 1, y, path, step + 1);

            path[step] = 'd';
            pathfind(maze, x, y - 1, path, step + 1);

            path[step] = 'r';
            pathfind(maze, x + 1, y, path, step + 1);
        }

        maze[x][y] = ' ';
    }
}

/*
    Write a function that accepts an 8 by 8 array of characters that represents a maze.
    Each position can contain either an X or a blank.
    Starting at position (0,1), list any path through the maze to get to locatipon (7,7).
    Only horizontal and vertical moves are allowed.
    If no path exists, write a message indication there is no path.
    Moves can be made only to locations that contain a blank.
    If an X is encountered, that path is blocked and another must be chosen.
    Use recursion.
*/