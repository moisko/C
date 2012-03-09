#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "exerciceiv.h"

void init_string(str string) {
    char c;
    int i = 0;
    while (c = getchar(), c != '\n' && c != EOF && i < DIM - 1) {
        *string++ = c;
        i++;
    }
    *string = '\0';
}

int contains(str string, str sub) {
    while (*sub && *string)
        if (*sub != *string) return (0);
        else {
            string++;
            sub++;
        }

    return (!(*sub));
}

int findmatch(char *pattern, char *text) {
    int i, j, pLength, tLength;
    pLength = strlen(pattern);
    tLength = strlen(text);
    for (i = 0; i <= (tLength - pLength); i++) {
        j = 0;
        while ((j < pLength) && (text[i + j]) == pattern[j]) {
            j++;
        }
        if (j == pLength) return (i);
    }

    return (-1);
}

void search(str string, str sub) {
    int pos = 0;
    while (*string) {
        if (contains(string, sub)) {
            printf("Found at position %d\n", pos);
        }
        string++;
        pos++;
    }
}

char * find_substring(str string, str sub) {
    if (toupper(getchar()) == 'Y') {
        scanf("%s", sub);
    }
    return strstr(string, sub);
}

char * delete_substring(str string, str sub) {

    // provide implementation

    return string;
}
