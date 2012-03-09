#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define LINES 3

#define MAX_LINE_LENGTH 62

char *enterTextLine(char *textLine);

int enterText(char *text[]);

void echoText(char *text[], int lines);

void sortText(char *text[], int lines);

int getMaxLineLength(char *text[], int lines);

void getAllLinesWithMatchingPattern(char *text[], int lines, char *pattern);

void swapTextLines(char *text[], int lines, int line1, int line2);

int findMatch(char *pattern, char *textLine);

int main(void) {
	char *text[LINES];

	int lines = enterText(text);
	printf("Text at the beginning\n");
	echoText(text, lines);

	sortText(text, lines);
	printf("Text after sorting\n");
	echoText(text, lines);

	printf("Max line length %d\n", getMaxLineLength(text, lines));

	printf("Swapped text lines\n");
	swapTextLines(text, lines, 0, 1);
	echoText(text, lines);

	getAllLinesWithMatchingPattern(text, lines, "some");

	return EXIT_SUCCESS;
}

char *enterTextLine(char *textLine) {
	char c, *pTextLine = textLine;
	int i = 0;
	while (c = getchar(), c != '\n' && c != EOF) {
		*textLine++ = c;
		i++;
	}
	if (i == 0 && c == EOF)
		return NULL;
	else {
		*textLine = '\0';
		return pTextLine;
	}
}

int enterText(char *text[]) {
	int line = 0;
	char *textLine = (char*) malloc(MAX_LINE_LENGTH);
	while (line < LINES) {
		enterTextLine(textLine);
		int lineLength = strlen(textLine);
		text[line] = (char *) malloc(lineLength + 1);
		if (text[line] == NULL) {
			exit(EXIT_FAILURE);
		}
		strcpy(text[line], textLine);
		line++;
	}

	return line;
}

int getMaxLineLength(char *text[], int lines) {
	int maxLineLength = strlen(text[0]);
	int line;
	for (line = 1; line < lines; line++) {
		int currentLineLength = strlen(text[line]);
		if (currentLineLength > maxLineLength) {
			maxLineLength = currentLineLength;
		}
	}

	return maxLineLength;
}

void getAllLinesWithMatchingPattern(char *text[], int lines, char *pattern) {
	int line;
	for (line = 0; line < lines; line++) {
		int position = findMatch(pattern, text[line]);
		if ((position) != EOF) {
			printf("Pattern '%s' found at position %d\n", pattern, position);
		}
	}
}


int findMatch(char *pattern, char *textLine) {
	int i, j;
	int m, n;

	m = strlen(pattern);
	n = strlen(textLine);

	for (i = 0; i <= (n - m); i++) {
		j = 0;
		while ((j < m) && (textLine[i + j] == pattern[j])) {
			j++;
		}
		if (j == m) {
			return i;
		}
	}

	return EOF;
}

void swapTextLines(char *text[], int lines, int line1, int line2) {
	char *temp;
	temp = text[line1];
	text[line1] = text[line2];
	text[line2] = temp;
}

void echoText(char *text[], int lines) {
	int currentLine;
	for (currentLine = 0; currentLine < lines; currentLine++)
		puts(text[currentLine]);
}

void sortText(char *text[], int lines) {
	int i, j;
	for (i = lines - 1; i > 0; i--) {
		int modified = 0;
		for (j = 0; j < i; j++)
			if (strcmp(text[j], text[j + 1]) > 0) {
				char *temp = text[j];
				text[j] = text[j + 1];
				text[j + 1] = temp;
				modified = 1;
			}
		if (!modified)
			break;
	}
}

