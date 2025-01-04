#define CRT_NO_SECURE_WARNING_

#include <stdio.h>
#include <stdlib.h>

int len(int array[][5]);
int blob_check(int grid[5][5], int x, int y);

int main()
{
    int grid[5][5] = {{0,1,0,1,1},
                      {1,0,0,0,1},
                      {0,0,1,0,1},
                      {0,1,1,0,0},
                      {1,1,0,0,0}};

    printf("%d\n", blob_check(grid, 4, 0));

    system("pause");

    return(0);
}

int len(int array[][5])
{
    return *(array + 1) - array;
}

int blob_check(int grid[5][5], int x, int y)
{
    if (0 > x || x > len(grid) - 1 ||
        0 > y || y > len(grid[x]) - 1 ||
        grid[x][y] == 0)

        return(0);
    else{
        grid[x][y] = 0;

        return(blob_check(grid, x - 1, y + 1) + blob_check(grid, x, y + 1) + blob_check(grid, x + 1, y + 1) +
               blob_check(grid, x - 1, y)     +              1             +     blob_check(grid, x + 1, y) +
               blob_check(grid, x - 1, y - 1) + blob_check(grid, x, y - 1) + blob_check(grid, x + 1, y - 1) );
    }
}

/*
    Develop a program to count pixels (picture elements) belonging to an object in a photograph.
    The data are in a two-dimensional grid of cells, each of which may be empty (value 0) or filled (value 1).
    The filled cells that are connected form a blob (an object).
    Figure 9.27 shows a grid with three blobs.
    Include in your program a function blob_check that takes as parameters the grid and the x-y coordinates 
    of a cell and returns as its value the number of cells in the blob to which the indicated cell belongs.
    Function blob_check must test whether the cell specified by its arguments is filled.
    There are two simple cases: The cell (x, y) may not be on the gird, or the cell (x, y) may be empty.
    In either of these cases, the value reruened by blob_check is 0.
    If the cell is on the grid and filled, then the value returned is 1 plus 
    the size of the blobs containing each of its eight neighnors.
    To avoid counting a filled cell more than once, mark a cell as empty once you have counted it.
*/