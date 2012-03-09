#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_LENGTH 20

#define NUMBER_OF_WORDS 5

void sort(char *words[], int n);

void echo(char *message, char *words[], int n);

char *enterWord(char *word);

char **enterWords(char **words, int n);

void insertionSort(char **words, int n);

void selectionSort(char **words, int n);

void swapWords(char **words, int word1Index, int word2Index);

int main(void) {
	char *words[NUMBER_OF_WORDS];

	puts("Enter words\n");
	enterWords(words, NUMBER_OF_WORDS);

//	sort(words, NUMBER_OF_WORDS);
//	echo("Sorted words", words, NUMBER_OF_WORDS);

//	insertionSort(words, NUMBER_OF_WORDS);
//	echo("Sorted words - Insertion sort", words, NUMBER_OF_WORDS);

	selectionSort(words, NUMBER_OF_WORDS);
	echo("Sorted words - Selection sort", words, NUMBER_OF_WORDS);

	return EXIT_SUCCESS;
}

char *enterWord(char *word) {
	if (!*word) {
		printf("Allocation memory\n");
		exit(EXIT_FAILURE);
	}
	scanf("%s", word);

	return word;
}

char **enterWords(char **words, int n) {
	int i = 0;
	while (i < n) {
		printf("word[%d]\t", i);
		char *word = (char *) malloc(WORD_LENGTH * sizeof(char));
		enterWord(word);
		words[i] = (char *) malloc(strlen(word));
		if (!*words[i]) {
			printf("Allocation memory\n");
			exit(EXIT_FAILURE);
		}
		strcpy(words[i], word);
		i++;
	}

	return words;
}

void echo(char *message, char *words[], int n) {
	printf("\n%s\n", message);
	int i;
	for (i = 0; i < n; i++)
		printf("%s\n", words[i]);
}

void insertionSort(char **words, int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		j = i;
		while ((j > 0) && (strcmp(words[j], words[j - 1]) < 0)) {
			swapWords(words, j, j - 1);
			j = j - 1;
		}
	}
}

void swapWords(char **words, int word1Index, int word2Index) {
	char *temp;
	temp = words[word2Index];
	words[word2Index] = words[word1Index];
	words[word1Index] = temp;
}

void selectionSort(char **words, int n) {
	int i, j, minIndex; /* counters */
	/* index of minimum */
	for (i = 0; i < n; i++) {
		{
			minIndex = i;
		}
		for (j = i + 1; j < n; j++)
			if (strcmp(words[j], words[minIndex]) > 0)
				minIndex = j;
		swapWords(words, i, minIndex);
	}
}

void sort(char *words[], int n) {
	for (;;) {
		int i, ok = 1;
		for (i = 1; i < n; i++)
			if (strcmp(words[i - 1], words[i]) > 0) {
				char *w = words[i - 1];
				words[i - 1] = words[i];
				words[i] = w;
				ok = 0;
			}
		if (ok)
			return;
		n--;
	}
}
