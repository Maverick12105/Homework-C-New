#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* strings[] = { "level", "deed", "sees", "madamimadam" };

    /*
    char *strings[] = {"level", "deed", "sees", "Madam I'm Adam"};
    
    printf("%d", strlen(strings));
    for (int i = 0; i < strlen(strings); ++i) {
        strcpy(temp_string, "");
        for (int j = 0; strlen(strings[i]); ++j){
            printf("%d", 'a' <= strings[i][j] && strings[i][j] <= 'z');
            if ('a' <= strings[i][j] && strings[i][j] <= 'z') {
               temp_string[u] = strings[i][j];
                ++u;}
            else if ('A' <= strings[i][j] && strings[i][j] <= 'Z') {
                temp_string[u] = strings[i][j] + ' ';
                ++u;}
            }
        printf("%s", temp_string);
    }
    printf("%s", deblanke_unpunctuating(strings[3]));
    */

    for (int i = 0; i < 4; ++i) {
        printf("%d", is_palindrome(strings[i], 0, strlen(strings[i])));
    }

    system("pause");

    return(0);
}

int is_palindrome(char string[], int letter_pos, int str_len)
{
    if (letter_pos >= str_len)
        ;
    else if (string[letter_pos] == string[str_len - 1] && is_palindrome(string, letter_pos + 1, str_len - 1))
        return (1);
    else
        return (0);
}
/*
char* deblanke_unpunctuating(char string_in[])
{
    char string_out[20] = {};
    string_out[0] = string_in[0];
    printf("%s", string_out);
    
    for (int i = 0; i < strlen(string_in); ++i) {
        if ('a' <= string_in[i] && string_in[i] <= 'z')
            strcat(string_out, string_in[i]);
        else if ('A' <= string_in[i] && string_in[i] <= 'Z')
            strcat(string_out, string_in[i] + ' ');

        printf("a%s\n", string_out);
    }

    return(string_out);
}
*/
/*
    A palindrome consists of a word or deblanked, unpunctuated phrase that is spelled exatly the same when the letters are reversed.
    Write a recursive function that returns a value of 1 if its string argument is a palindrome.
    Notice that in palindromes such as level, deed, sees, and Madam I'm Adam (madamimadam), 
    the first letter matches the last, the second matches the next-to-last, and so on.
*/