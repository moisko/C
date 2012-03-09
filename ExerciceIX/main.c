#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define STACK_SIZE 5

typedef float Item;

typedef struct {
	Item items[STACK_SIZE];
	int top;
} Stack;

void push(Stack *S, float element);

float pop(Stack *S);

void init(Stack *S);

int isFull(Stack *S);

int isEmpty(Stack *S);

void echo(char *message, Stack *S);

int main(void) {
	Stack S;

	init(&S);

	Item item;
	do {
		scanf("%f", &item);
		push(&S, item);
	} while (getchar() != EOF);

	echo("Stack content", &S);

	return EXIT_SUCCESS;
}

void init(Stack *S) {
	S->top = 0;
}

void push(Stack *S, Item element) {
	if (!isFull(S)) {
		S->items[S->top] = element;
		(S->top)++;
	}
}

float pop(Stack *S) {
	(S->top)--;
	return (S->items[S->top]);
}

int isFull(Stack *S) {
	return (S->top >= STACK_SIZE);
}

int isEmpty(Stack *S) {
	return S->top == 0;
}

void echo(char *message, Stack *S) {
	int i;
	if (S->top == 0)
		return;
	else {
		printf("\n%s\n", message);
		for (i = 0; i < S->top; i++)
			printf("%g    ", S->items[i]);
	}
}
