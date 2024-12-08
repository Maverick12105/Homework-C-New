#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x1, y1, x2, y2;

    printf("input point a (x1, y1) => ");
    scanf(" (%lf, %lf)", &x1, &y1);
    printf("input point b (x2, y2) => ");
    scanf(" (%lf, %lf)", &x2, &y2);

    printf("(%.1lf, %.1lf), (%.1lf, %.1lf), y=%.1lfx%+.2lf\n",
        x1, y1, x2, y2, 
        -(x2 - x1) / (y2 - y1),
        (y1 * y1 - y2 * y2 + x1 * x1 - x2 * x2) / (2 * (y1 - y2)));

    system("pause");

    return(0);
}

/*
    Write a program that outputs the equation of the perpendicular bisector of the line segment between two points.
    Your program should
        Prompt for and input coordinates of the two points [for example, try the points (2.0, -4.0) and (7.0, -2.0)];
        Compute the slope of the line between those two points;
        Compute the coordinates of the midpoint of the line segment between the two points 
        by averaging the two x-coordinates and the two y-coordinates;
        Compute the slope of the perpendicular bisector by taking the negative reciprocal of the slope of the line segment;
        Compute the y-intercept of the perpendicular bisector 
        (you now have the slope m of the bisector and a point (xmid, ymid) on the bisector, so the y-intercept is ymid - mxmid);
        Output with labels the original two points, and outout in y = mx + b format the equation of the perpendicular bisector.
    Test your program to be sure it works on different pairs of points.
    However, there will be some pairs of points for which you can't make your program work (at least not at this stage).
    Think about what points will cause your program to fail, and write a paragraph describing which points fall in this category.
*/