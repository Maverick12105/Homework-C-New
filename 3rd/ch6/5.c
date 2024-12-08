#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int number_reverse(int input);
int number_check_prime(int input);
int number_check_palindrome(int input);
void print_bool(int input);

int main()
{
    int number_list[6] = { 323, 12242, 9, 463, 678, 8679 };

    for (int i = 0; i < 6; ++i)
    {
        printf("Number = %d\n", number_list[i]);
        printf("Reversed = %d\n", number_reverse(number_list[i]));
        printf("Prime = ");
        print_bool(number_check_prime(number_list[i]));
        printf("Palindrome = ");
        print_bool(number_check_palindrome(number_list[i]));
    }

    printf("%d", number_check_prime(101));

    system("pause");

    return(0);
}

int number_reverse(int input)
{
    int output = 0;
    while (input > 0)
    {
        output = output * 10 + input % 10;
        input /= 10;
    }
    return(output);
}

int number_check_prime(int input)
{
    int temp = input;

    for (int i = 2; i < temp; ++i)
    {
        if (input % i == 0)
            return(0);
        temp = input / i;
    }
    return(1);
}

int number_check_palindrome(int input)
{
    if (input == number_reverse(input))
        return(1);
    else
        return(0);
}

void print_bool(int input)
{
    if (input == 0)
        printf("False\n");
    else
        printf("True\n");
}

/*
    Given a list of positive integers, perform the following tasks:
        a. Reverse a give number.
        b. Check whether the given number is prime or not.
        c. Check whether the given number is a palindrome or not.
    You should write each of the above as a separate program with functions that send back the answers to these three questions.
    Some sample input data might be
        323 12242 09 463 678 8679
*/