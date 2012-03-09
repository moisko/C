#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

int length(char *s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

int getWordsCount(char *s) {
	int n, token = 0;
	for (n = 0; *s; s++) {
		if (isspace(*s))
			token = 0;
		else if (!token) {
			token = 1;
			n++;
		}
	}

	return n;
}

char *search_substr(char *str, char *substring) {
	int t;
	char *p, *p2, *start;
	for (t = 0; str[t]; t++) {
		p = &str[t];
		start = p;
		p2 = substring;
		while (*p2 && *p2 == *p) {
			p++;
			p2++;
		}
		if (!*p2)
			return start;
	}

	return NULL;
}

bool equals(char *s1, char *s2) {
	if (length(s1) == length(s2)) {
		int i;
		for (i = 0; i < length(s1); i++) {
			if (s1[i] == s2[i]) {
				continue;
			} else
				return false;
		}
		return true;
	}
	return false;
}

int indexOf(char *s, char *substring) {
	int i, j;
	int pos = EOF;
	for (i = 0; s[i] != 0; i++) {
		for (j = 0; substring[j] != 0; j++) {
			if (s[i + j] != substring[j]) {
				break;
			}
		}
		if (substring[j] == 0) {
			pos = i;
			break;
		}
	}

	return pos;
}

bool contains(char *s, char *substr) {
	// provide implementation

	return false;
}

void strcopy(char *s, char *t) {
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

int strcmp(char *s, char *t) {
	for (; *s == *t; s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}

	return *s - *t;
}
