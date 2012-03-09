#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 80

FILE *writef_fputc(char *fileName);

FILE *writef_fputs(char *fileName);

int readf_fgetc(FILE *fp, char *fileName);

int readf_fgets(FILE *fp, char *fileName);

int readf_getc(FILE *fp, char *fileName);

int copy(int fromLine, int toLine, FILE *fromFile, FILE * toFile);

int main(void) {
	char *fileName = "output.txt";
	FILE *fp = writef_fputs(fileName);
	// FILE *fp = writef_fputc(fileName);
	if (fp != NULL)
		printf("\nFile %s created\n\n", fileName);

	printf("Reading file %s with fgetc() function\n", fileName);
	readf_fgetc(fp, fileName);

	printf("Reading file %s with getc() function\n", fileName);
	readf_getc(fp, fileName);

	printf("Reading file %s with fgets() function\n", fileName);
	readf_fgets(fp, fileName);

	// Remove output.txt before leaving main
	remove(fileName);

	return EXIT_SUCCESS;
}

FILE *writef_fputc(char *fileName) {
	// Create a text file for writing
	FILE *file = fopen(fileName, "w");
	if (file == NULL) {
		printf("Cannot open file %s", fileName);
	} else {
		fflush(stdin);
		int ch;
		while ((ch = getchar()) != EOF)
			// Write a character to a file
			fputc(ch, file);
		fclose(file);
	}
	return (file);
}

FILE *writef_fputs(char *fileName) {
	FILE *fp;
	if ((fp = fopen(fileName, "w")) == NULL) {
		printf("Cannot open file %s", fileName);
	} else {
		char str[LENGTH];
		do {
			gets(str);
			strcat(str, "\n"); // add a new line
			fputs(str, fp);
		} while (*str != '\n');
		fclose(fp);
	}
	return fp;
}

int readf_fgets(FILE *fp, char *fileName) {
	if ((fp = fopen(fileName, "r")) == NULL) {
		printf("Cannot open file %s", fileName);
		return EXIT_FAILURE;
	} else {
		char buffer[LENGTH];
		while (!feof(fp)) {
			fgets(buffer, LENGTH, fp);
			if (!feof(fp)) {
				printf("%s", buffer);
			}
		}
		fclose(fp);
		return EXIT_SUCCESS;
	}
}

int readf_fgetc(FILE *fp, char *fileName) {
	// Open a text file for reading
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Cannot open file %s", fileName);
		return (EXIT_FAILURE);
	} else {
		int ch, flag;
		// Read a character from a file
		while ((ch = fgetc(fp)) != EOF) {
			flag = 1;
			// Print on screen
			putchar(ch);
		}
		fclose(fp);
		if (!flag)
			printf("File %s is empty\n", fileName);
		return (flag);
	}
}

int readf_getc(FILE *fp, char *fileName) {
	if ((fp = fopen(fileName, "r")) == NULL) {
		printf("Cannot open file %s", fileName);
		return EXIT_FAILURE;
	} else {
		int ch;
		while (!feof(fp)) {
			ch = getc(fp);
			if (!feof(fp))
				// Print on screen
				putchar(ch);
		}
		fclose(fp);
		return EXIT_SUCCESS;
	}
}

int copy(int fromLine, int toLine, FILE *fromFile, FILE * toFile) {

	// TODO provide implementation

	return EXIT_FAILURE;
}
