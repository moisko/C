#ifndef EXERCICEIV_H
#define	EXERCICEIV_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DIM 40

    typedef char str[DIM];

    void init_string(str string);

    /**
     * Returns 0 if the given string does not contain sub, 1 otherwize.
     * 
     * @param string
     * @param sub
     * @return 0 if the given string does not contain sub, 1 otherwize
     */
    int contains(str string, str sub);

    void search(str string, str sub);

    /**
     * Finds a sub-string within a string.
     * 
     * @param string
     * @param sub
     * @return pointer to the beginning of the sub-string or NULL if not found.
     */
    char * find_substring(str string, str sub);
    
    int findmatch(char *pattern, char *text);

    /**
     * Deletes all occurences of sub from string.
     * 
     * @param string
     * @param sub
     * @return pointer to the new string with all deleted occurences of sub
     */
    char * delete_substring(str string, str sub);

#ifdef	__cplusplus
}
#endif

#endif
