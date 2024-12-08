#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>
#include <stdlib.h>

int main()
{
    int data[3] = {1,2,3};

    system("pause");

    return(0);
}

int binary_srch(int data[], int target)
{
    int bottom = data[0];
    int top = data[sizeof(data) - 1];
    int found = false;
    int middle;
    int index;

    while (bottom <= top && found != true) {
        middle = (bottom + top) / 2;
        if (data[middle] == target) {
            found = true;
            index = middle;
        }
        else if (data[middle] > target)
            top = middle - 1;
        else
            bottom = middle + 1;
    }
}

/*
    The binary search algorithm that follows may be used to search an array when the elements are in order.
    This algorithm is analogous to the following approach for finding a name in a telephone book.
        a. Open the book in the middle, and look at the middle name on the page.
        b. If the middle name isn't the one you're looking for, decide whether it comes before or after the name you want.
        c. Take the appropriate galf of the section of the book you were looking in and repeat these steps until you land on the name.
    ALGORITHM FOR BINARY SEARCH
        1. Let bottom be the subscript of the initial array element.
        2. Let top be the subscript of the last array element.
        3. Let found be false.
        4. Repeat as long as bottom isn't greater than top and the target has not been found
            5. Let middle be the subscript of the element halfway between bottom and top.
            6. If the element at middle is the target
                7. Set found to true and index to middle.
            else if the element at middle is larger than the target
                8. Let top be middle - 1.
            else
                9. Let bottom be middle + 1.
    Write and test a funcuion binary_srch that implements this algorithm for an array of integers.
    When there is a large number of array elements, which function do you think is faster:
        binary_srch or the linear search function of Fig. 7.14?
*/