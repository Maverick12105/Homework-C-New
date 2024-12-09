#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_names(char a[], char b[]);
int search(char source[], int index_min, int index_max);

int main()
{
    char names[100][12];
    char temp[10];
    int j;

    FILE* name_file_input = fopen("Girls.txt", "r");
    FILE* name_file_output = fopen("Girls_sorted.txt", "w");

    for (int i = 0; i < 100; ++i)
        fgets(names[i], 12, name_file_input);
    
    for (int i = 0; i < 100; ++i) {
        swap_names(&names[i], &names[search(names, i, 100)]);

        fprintf(name_file_output, "%s", names[i]);
    }

    fclose(name_file_input);
    fclose(name_file_output);

    system("pause");

    return(0);
}

void swap_names(char a[], char b[])
{
    char temp[12];

    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int search(char source[][12], int index_min, int index_max)
{
    char name_min[12];
    strcpy(name_min, source[index_min]);
    int name_min_index = index_min;

    for (int i = index_min; i < index_max; ++i)
        if (strcmp(name_min, source[i]) > 0) {
            strcpy(name_min, source[i]);
            name_min_index = i;
        }

    return(name_min_index);
}