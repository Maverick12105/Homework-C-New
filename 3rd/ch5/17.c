#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trap(double a, double b, double n, double f(double));
double g(double x);
double h(double x);

int main()
{
    printf("For x^2 * sin(x) (a = 0, b = 3.14159)\n");
    for (int i = 1; i < 8; ++i)
        printf("When n = %.0lf, T = %lf\n", pow(2, i), trap(0, 3.14159, pow(2, i), g));

    printf("For กิ(4 - x^2) (a = -2, b = 2)\n");
    for (int i = 1; i < 8; ++i)
        printf("When n = %.0lf, T = %lf\n", pow(2, i), trap(-2, 2, pow(2, i), h));

    system("pause");

    return(0);
}

double trap(double a, double b, double n, double f(double))
{
    double sum = 0;
    double h;
    if (n == 0)
        h = b - a;
    else
        h = (b - a) / n;

    for (int i = 1; i < n; ++i)
    {
        sum += f(a + h * i);
    }

    return(h * (f(a) + f(b) + 2 * sum) / 2);
}

double g(double x)
{
    return(pow(x, 2) * sin(x));
}

double h(double x)
{
    return(sqrt(4 - pow(x, 2)));
}

/*
    You would like to find the area under the curve y = f(x) betweem the lines x = a and x = b.
    One way to approximate this area is to use line segments as approximations of small pieces of the curve 
    and then to sum the areas of trapezoids created by drawing perpendiculars from the line segment endpoints to the x-axis,
    as shown in Fig. 5.26.
    We will assume that f(x) is non-negative over the interval [a, b].
    The trapezoidal rule approximates this area T as
        T = (h * 2) * (f(a) + f(b) + ...
    for n subintervals of length h:
        h = (b - a) / n
    Write a function trap with input parameters a, b, n, and f that implements the trapezoidal rule.
    Call trap with values for n of 2, 4, 8, 16, 32, 64, and 128 on functions
        g(x) = x^2 * sin(x) (a = 0, b = 3.14159)
        h(x) = กิ(4 - x^2) (a = -2, b = 2)
    Function h defines a half-circle of raduis 2.
    Compare your approximation to the actual area of this half-circle.
    Note: If you have studied calculus, you will observe that the trapezoidal rule is approximating ...
*/