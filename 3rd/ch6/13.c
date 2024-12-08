#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char transition_char;
    enum States {start, build_num, number, build_id, identifier, stop} current_state;

    current_state = start;
    do {
        if (current_state == identifier) {
            printf(" - Identifier\n");
            current_state = start;
        } else if (current_state == number) {
            printf(" - Number\n");
            current_state = start;
        }
        scanf("%c", &transition_char);  //a 1  a1 1a   a.1 1.1  a1.1 1a.1    -a -1  -a1 -1a   -a.1 -1.1  -a1.1 -1a.1 .
        if (transition_char != ' ')
            printf("%c", transition_char);
        current_state = transition(current_state, transition_char);
    } while (current_state != stop);

    system("pause");

    return(0);
}

int transition(int current_state, int transition_char)
{
    enum States { start, build_num, number, build_id, identifier, stop };

    if (transition_char == '.' && current_state == start)
        return(stop);
    if (transition_char == ' ')
    {
        if (current_state == build_id)
            return(identifier);
        if (current_state == build_num)
            return(number);
        return(start);
    }
    if (current_state == build_id || (isdigit(transition_char) == 0 && transition_char != '-' && transition_char != '.'))
        return(build_id);
    if (isdigit(transition_char) > 0 && transition_char != '-' && transition_char != '.')
        return(build_num);
}

/*
    A finite state machine (FSM) consists of a set of states, a set of transitions, and a string of input data.
    In the FSM of Fig. 6.19, the named ovals represent states, and the arrows connection the states represent transitions.
    The FSN is designed to recognize a list of C identifiers and nonnegative integers,
    assuming that the items are ended by one or more blanks and that a period marks the end of all the data.
    The following table traces how the diagrammed machine would process a string composed of one blank,
    the digit 9 and 5, two blanks, the letter K, the digit 9, one blank, and a period.
    The machine begins in the start state.

    Write a program that uses an enumerated type to represent the names of the states.
    Your program should process a correctly formatted line of data, identifying each data item.
    Here is a sample of correct input and output.
        Input:
            rate R2D2 48   2 time   555666
        Output:
            rate - Identifier
            R2D2 - Identifier
            48 - Number
            2 - Number
            time - Identifier
            555666 - Number
    Use the following code fragment in main, and design function transition 
    to reture the next state for all the numbered transitions of the finite state machine.
    If you include the header file ctype.h, you can use the library function isdigit,
    which return 1 if called with a digit character, 0 otherwise.
    Similarly, the function isalpha checks whether a character is a letter.
    When your program correctly models the behavior of the FSM shown,
    extend the FSM and your program to allow optional signs and optional fractional parts 
    (i.e., a decimal point followed by zero or more digits) in numbers.

    current_state = start;
    do {
        if (current_state == identifier) {
            printf(" - Identifier\n");
            current_state = start;
        } else if (current_state == number) {
            printf(" - Number\n");
            current_state = start;
        }
        scanf("%c", &transition_char);
        if (transition_char != ' ')
            printf("%c", transition_char);
        current_state = transition(current_state, transition_char);
    } while (current_state != stop);
*/