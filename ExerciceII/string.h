#ifndef STRING_H
#define	STRING_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#define LENGTH 62

    int length(char *s);

    int getWordsCount(char *s);

    char *search_substr(char *s, char *substring);

    bool equals(char *s1, char *s2);

    /* Returns the index within this string of the first occurrence of the specified substring */
    int indexOf(char *s, char *substring);

    /* Returns true if and only if this string contains the specified sequence */
    bool contains(char *s, char *substr);

    void strcopy(char *s, char *t);

    int strcmp(char *s, char *t);

#ifdef	__cplusplus
}
#endif

#endif	/* STRING_H */

