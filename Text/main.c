#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "text.h"

int main(void) {
    char buffer[LINE_LENGTH];
    char **text;
    
    if ((text = (char **) malloc(NUMBER_OF_LINES * sizeof (char *))) == NULL) {
        printf("Allocation error!\n");
        exit(1);
    }
    
    int lineNumber = 0;
    do {
        // Enter a line from stdin
        if (fgets(buffer, sizeof (buffer), stdin) == NULL) {
            printf("Error while reading!\n");
            exit(1);
        }
        if ((text = insert(text, lineNumber, buffer)) == NULL) {
            printf("Allocation error!\n");
            exit(1);
        }
        lineNumber++;
    } while (lineNumber < NUMBER_OF_LINES);

    printf("\nOriginal text entered from stdin:\n");
    output(text, NUMBER_OF_LINES);
    // qsort is also an option -> part of stdlib.h header
    sort(text, NUMBER_OF_LINES);
    printf("Sorted list of strings:\n");
    output(text, NUMBER_OF_LINES);
    free_m(text, NUMBER_OF_LINES);

    return (EXIT_SUCCESS);
}

