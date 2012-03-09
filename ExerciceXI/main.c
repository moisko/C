#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCTION_NAME_LENGTH 20

int calculatePerimeter(int a, int b, int c);

int calculateSurface(int a, int b, int c);

// Array of function pointers
int (*p[2])(int a, int b, int c);

// Function pointer
int (*fp)(int a, int b, int c);

// Function table
struct function_table {
	char *name;
	int (*function)(int a, int b, int c);
};

int main(void) {
	int perimeter, surface, a, b, c;

	printf("Enter a: ");
	scanf("%d", &a);

	printf("Enter b: ");
	scanf("%d", &b);

	printf("Enter c: ");
	scanf("%d", &c);

	p[0] = calculatePerimeter; // address of calculateP..
	p[1] = calculateSurface; // address of calculateS...

	// to call the first function
	perimeter = (*p[0])(a, b, c);

	// to call the second function
	surface = (*p[1])(a, b, c);

	printf("The perimeter is: %d\n", perimeter);
	printf("The surface is: %d\n", surface);

	// Assign fp to the address of calculateSurface
	fp = &calculateSurface;
	printf("Calculate surface: %d\n", (*fp)(a, b, c));

	// Function table
	struct function_table my_table[] = { { "s", calculateSurface }, { "p",
			calculatePerimeter } };
	// Type s or p from the command line
	printf("Invoke function: ");
	char *functionName = (char *) malloc(
			MAX_FUNCTION_NAME_LENGTH * sizeof(char));
	scanf("%s", functionName);
	// Invoke calculateSurface or calculatePerimeter
	if (strcmp(functionName, my_table[0].name) == 0) {
		// Invoke calculateSurface by its name
		int surface = my_table[0].function(a, b, c);
		printf("surface = %d\n", surface);
	} else if (strcmp(functionName, my_table[1].name) == 0) {
		// Invoke calculatePerimeter by its name
		int perimeter = my_table[1].function(a, b, c);
		printf("perimeter = %d\n", perimeter);
	}

	return EXIT_SUCCESS;
}

int calculatePerimeter(int a, int b, int c) {
	int perimeter = 0;

	// TODO provide implementation

	return perimeter;
}

int calculateSurface(int a, int b, int c) {
	int surface = 0;

// TODO provide implementation;

	return surface;
}
