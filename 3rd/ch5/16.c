#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double n, c;
    double next_aprox, current_aprox;
    int i = 0;
    
    printf("Index of radical => ");
    scanf(" %lf", &n);
    printf("Radicand => ");
    scanf(" %lf", &c);
    
    current_aprox = c / 2 - (pow(c / 2, n) - c) / (n * pow(c / 2, n - 1));

    for (i = 0; i < 100; ++i)
    {
        next_aprox = current_aprox - (pow(current_aprox, n) - c) / (n * pow(current_aprox, n - 1));
        if ((int)(next_aprox * 1000000) == (int)(current_aprox * 1000000)) {
            printf("%.0lf《%.0lf = %.6lf\n\n", n, c,current_aprox);
            break;}
        else if (next_aprox < current_aprox){
            current_aprox = next_aprox;
            continue;}
        else {
            printf("Failed to converge\n\n");
            break;}
        
    }
    if (i == 100)
        printf("%.0lf《%.0lf = %.6lf\n\n", n, c, current_aprox);

    system("pause");

    return(0);
}

/*
    In this chapter, we studied the bisection method for finding a root of an equation.
    Another method for finding a root, Newton's method, 
    usually converges to a solution even faster than the bisection method, if it converges at all.
    Newton's method starts with an initial guess for a root, x0, and then generates successive approximate roots
    x1, x2, ... , xj, xj + 1, using the formula
        xj + 1 = xj - f(xj) / f'(xj)
    where f'x(x) is the derivative of function f evaluated at x = xj.
    The formula generates a new guess, xj + 1, from a previous one.
    Sometimes Newton's method will fail to converge to a root.
    In this case, the program should terminate after many trials, perhaps 100.

    Figure 5.25 shows the geometric interpretation of Newton's method where x0, x1, and x2 represent successive guesses for the root.
    At each point xj, the derivative, f'(xj), is t

    Write a program that uses Newton's method to approximate the nth root of a number to six decimal places.
    If pow(x, n) = c, then pow(x, n) - c = 0.
    Finding a root of the second equation will give you n《c.
    Test your program on 《2, 3《7, and 3《-1.
    Your program could use c / 2 as its initial guess.
*/