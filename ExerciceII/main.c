#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void getStringFromSystemIn(char *);

int main(void) {
    char str1[LENGTH];
    getStringFromSystemIn(str1);
    printf("s1 = '%s', length(s1) = %d\n", str1, length(str1));

    char str2[LENGTH];
    getStringFromSystemIn(str2);
    printf("s2 = '%s', length(s2) = %d\n", str2, length(str2));

    if (equals(str1, str2)) {
        printf("Les deux chaines de caracteres sont egales!\n");
    } else printf("Les deux chaines de caractere NE sont pas egales!\n");

    char sub1[LENGTH] = {0};
    getStringFromSystemIn(sub1);
    printf("Position de '%s' dans '%s' est: %d\n", sub1, str1, indexOf(str1, sub1));

    char *start = search_substr(str1, sub1);
    if (start != NULL) {
        printf("'%s' trouve!", start);
    } else printf("'%s' NE contient pas '%s'!", str1, sub1);

    return EXIT_SUCCESS;
}

void getStringFromSystemIn(char *s) {
    char c;
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < LENGTH) {
        *s++ = c;
        i++;
    }
    *s = '\0';
}
