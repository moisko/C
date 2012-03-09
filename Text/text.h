#ifndef TEXT_H
#define	TEXT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LINE_LENGTH 50
#define NUMBER_OF_LINES 6

    char **insert(char **text, int lineNumber, char *buffer);

    void output(char **text, int numberOfLines);

    void sort(char **text, int numberOfLines);

    void free_m(char **text, int numberOfLines);

#ifdef	__cplusplus
}
#endif

#endif	/* TEXT_H */

