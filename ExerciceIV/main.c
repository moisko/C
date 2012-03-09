#include <stdio.h>
#include <stdlib.h>

#include "exerciceiv.h"

int main(void) {
    char *string = (char *) malloc(DIM * sizeof (char));
    init_string(string);

    char *sub = (char *) malloc(DIM * sizeof (char));
    init_string(sub);

    search(string, sub);

    char *p = find_substring(string, sub);
    printf("Beginning of the sub-string:\n");
    printf("%s\n", p);

    printf("Match found at position '%d'\n", findmatch(sub, string));

    delete_substring(string, sub);
    printf("New string after deleting '%s' is: %s\n", sub, string);

    free(string);
    free(sub);

    return EXIT_SUCCESS;
}
