#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"

char **insert(char **text, int linesNumber, char *buffer) {
    char *p = (char *) malloc((strlen(buffer) + 1) * sizeof (char));
    strcpy(p, buffer);
    p[strlen(buffer)] = '\0';
    text[linesNumber] = p;
    return text;
}

void output(char **text, int numberOfLines) {
    int j;
    for (j = 0; j < numberOfLines; j++) {
        printf("%s", *(text + j));
    }
}

void sort(char **text, int numberOfLines) {
    int j, flag;
    char temp[LINE_LENGTH];
    do {
        flag = 0;
        for (j = 0; j < numberOfLines - 1; j++) {
            if (strcmp(*(text + j), *(text + j + 1)) > 0) {
                flag = 1;
                strcpy(temp, *(text + j));
                strcpy(*(text + j), *(text + j + 1));
                strcpy(*(text + j + 1), temp);
            }
        }
    } while (flag);
}

void free_m(char **text, int numberOfLines) {
    int i;
    for (i = 0; i < numberOfLines; i++) {
        free(text[i]);
    }
    free(text);
}

