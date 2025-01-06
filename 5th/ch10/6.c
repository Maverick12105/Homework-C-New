#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 12

typedef struct {
    char* language;
    int word_amount;
    char words[MAX_WORDS][21];
} wordlist_t;

void load_word_list(FILE* input_file, wordlist_t* wordlist);
void add_word(char* word, wordlist_t* wordlist);
int contains(char* word, wordlist_t wordlist);
int equal_list(wordlist_t wordlist_a, wordlist_t wordlist_b);
void display_word_list(wordlist_t wordlist);

int main()
{
    FILE* file_input = fopen("data.txt", "r");
    wordlist_t wordlist_file;
    wordlist_t wordlist_user;
    char word_input[21],
         language_input[21];

    load_word_list(file_input, &wordlist_file);
    
    wordlist_file.language[21];
    printf("Language => ");
    scanf("%s", language_input);
    wordlist_user.language = language_input;
    printf("\n");

    printf("Enter 12 words:\n");
    wordlist_user.word_amount = 0;
    for (int i = 0; i < 12; ++i) {
        printf("word %d => ", i + 1);
        scanf("%s", word_input);
        add_word(word_input, &wordlist_user);
    }
    printf("\n");

    printf("Enter a word to search in wordlist_file => ");
    scanf("%s", word_input);
    if (contains(word_input, wordlist_file))
        printf("Word \"%s\" exist in wordlist_file\n\n", word_input);
    else
        printf("Word \"%s\" doesn't exist in wordlist_file\n\n", word_input);

    wordlist_file.language = "Giberish";
    if (equal_list(wordlist_file, wordlist_user))
        printf("wordlist_file and wordlist_user are the same\n\n");
    else
        printf("wordlist_file and wordlist_user aren't the same\n\n");

    printf("wordlist_file");
    display_word_list(wordlist_file);
    printf("wordlist_user");
    display_word_list(wordlist_user);

    fclose(file_input);

    system("pause");

    return(0);
}

void load_word_list(FILE* input_file, wordlist_t* wordlist) {
    for (wordlist->word_amount = 0;

        wordlist->word_amount <= MAX_WORDS &&
        fscanf(input_file, "%s", &wordlist->words[wordlist->word_amount]) != EOF;

        ++wordlist->word_amount);
}

void add_word(char* word, wordlist_t* wordlist) {
    if (wordlist->word_amount >= MAX_WORDS)
        printf("List full, word not added.");
    else if (contains(word, *wordlist))
        ;
    else {
        strcpy(wordlist->words[wordlist->word_amount], word);
        ++wordlist->word_amount;
    }
}

int contains(char* word, wordlist_t wordlist) {
    for (int i = 0; i < wordlist.word_amount; ++i)
        if (strcmp(wordlist.words[i], word) == 0)
            return(1);
    return(0);
}

int equal_list(wordlist_t wordlist_a, wordlist_t wordlist_b) {
    if (strcmp(wordlist_a.language, wordlist_b.language) == 0 && wordlist_a.word_amount == wordlist_b.word_amount) {
        for (int i = 0; i < wordlist_a.word_amount; ++i)
            if (contains(wordlist_a.words[i], wordlist_b) == 0)
                return(0);
        return(1);
    }
    return(0);
}

void display_word_list(wordlist_t wordlist) {
    for (int i = 0; i < wordlist.word_amount; ++i) {
        if (i % 4 == 0)
            printf("\n");
        printf("%-20s ", wordlist.words[i]);
    }
    printf("\n\n");
}

/*
    Define a structure type to represent a word list.
    The structure will contain one string component for the language of the words (e.g., English, Japanese, Spanish),
    and integer component that keeps track of how many words are in the list,
    and an array of MAX_WORDS 20-character strings to hold the words.
    Define the following functions to work with word lists:
        a. load_word_list -- Takes as parmeters the name of an input file and a a wordlist structure to be filled.
        b. add_word -- Takes as parameters a word and a wordlist structure to modify.
           If the wordlist is already full, it displays the message "List full, word not added."
           If the word is already in the list, it leaves the structure unchanged.
           Otherwise, it adds the word to the list and updates the list size.
           Do not bother keeping the list in order.
        c. contains -- Takes as parameters a word and a wordlist.
           If the word matches one of the wordlist entries, the function retures true, otherwise false.
        d. equal_lists -- Takes two wordlists as parameters and returns true if the lists are in the same language,
           have the same number of elements, and every element of one list if found in the other. (Hint: Call contains repeatedly.)
        e. display_word_list -- Displays all the words of its wordlist structure parameter in four columns.
    Write a program that fills a wordlist from a data file.
    Then prompt the user to enter a language and 12 words to add to a different list.
    Then ask the user to enter some words to search for in the first list using contains,
    and print a message indication whether each is found.
    Use equal_lists to compare the two lists, printing an appropriate message.
    Finally, use display_word_list to output each list.
*/