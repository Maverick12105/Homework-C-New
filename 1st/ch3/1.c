#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double car_price, loan_pay, loan_interest, loan_month;

    printf("Price of the car => ");
    scanf(" %lf", &car_price);
    printf("Down payment => ");
    scanf(" %lf", &loan_pay);
    printf("Annual interest rate of the loan => ");
    scanf(" %lf", &loan_interest);
    printf("Loan period (month) => ");
    scanf(" %lf", &loan_month);

    printf("The loan is %.2lf$ total, and %.2lf$ for monthly payment.\n" ,car_price - loan_pay ,(car_price - loan_pay) * (loan_interest / 1200) / (1 - pow(1 + loan_interest / 1200, -loan_month)));

    system("pause");

    return(0);
}

/*
    You have saved $500 to use as a down payment on a car.
    Before beginning your car shopping, you decide to write a program to help you figure out what your monthly payment will be,
    given the car's purchase price, the monthly interest rate, and the time period over which you will pay back the loan.
    The formula for calculating your payment is
        payment = (i * P) / (1 - (1 + i) ^ -n)
    where
        P = principal (the amount you borrow)
        i = monthly interest rate (1/12 of the annual rate)
        n = total number of payments
    Your program should prompt the user for the purchase price, the down payment, 
    the annual interest rate, and the total number of payments (usaually 36, 48, or 60).
    It should then display the amount borrowed and the monthly payment including a dollar sign and two decimal places.
*/