#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 154368;
    int n_sum = 0;

    while (n > 10)
    {
        printf("%d\n", n % 10);
        n_sum = n_sum + n % 10;
        n = n / 10;
    }
    printf("%d\n", n);
    n_sum = n_sum + n;

    if (n_sum % 9 != 0)
        printf("non-Divisible");
    else
        printf("Divisible");

    system("pause");

    return(0);
}

/*
    An integer n is divisible by 9 if the sum of its digits is divisible by 9.
    Develop a program to display each digit, starting with the rightmost digit.
    Your program should also determine whether or not the number is divisible by 9.
    Test it on the following numbers:
        n = 154368
        n = 621594
        n = 123456
    Hint: use the % operator to get each digit; then use / to remove that digit.
    So 154368 % 10 gives 8 and 154368 / 10 gives 15436.
    The next digit extracted should be 6, then 3 and so on.
*/