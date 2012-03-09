#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void printMatrixRow(int *, int);

void insertionSort(int array[], int length);

int main(void) {
	int **matrix, matrixRows, matrixColumns, *sumOfMatrixColumns;
	// Enter matrix rows
	scanf("%d", &matrixRows);
	// Enter matrix columns
	scanf("%d", &matrixColumns);
	matrix = initMatrix(matrixRows, matrixColumns);
	// Print matrix
	printf("The matrix is\n");
	printMatrix(matrix, matrixRows, matrixColumns);
	// Calculate the sum of all matrix columns
	sumOfMatrixColumns = calculateSumOfMatrixColumns(matrix, matrixRows,
			matrixColumns);
	printf("The sum of each matrix column is\n");
	printMatrixRow(sumOfMatrixColumns, matrixColumns);
	// Insert a new matrix row
	printf("Inserting one additional row to matrix");
	printMatrixRow(sumOfMatrixColumns, matrixColumns);
	matrix = insertMatrixRow(matrix, matrixRows, matrixColumns,
			sumOfMatrixColumns);
	matrixRows++;
	printMatrix(matrix, matrixRows, matrixColumns);

	// Get min elements per column
	int *minElementsPerColumn = (int *) malloc(matrixColumns * sizeof(int));
	getMinElementsPerColumn(matrix, matrixRows, matrixColumns,
			minElementsPerColumn);
	printf("Min elements per column\n");
	printMatrixRow(minElementsPerColumn, matrixColumns);

	// Sort min elements per column
	insertionSort(minElementsPerColumn, matrixColumns);
	printf("Sorted min elements per column array\n");
	printMatrixRow(minElementsPerColumn, matrixColumns);

	// Free the memory used by sumOfMatrixColumns
	free(sumOfMatrixColumns);
	// Free the memory used by matrix
	freeMatrix(matrix, matrixRows);
	// printSumOfMatrixColumns(sumOfMatrixColumns, matrixColumns);

	return (EXIT_SUCCESS);
}

void printMatrixRow(int *matrixRow, int rowLength) {
	int index;
	for (index = 0; index < rowLength; index++) {
		printf("%4d", *(matrixRow + index));
	}
	printf("\n");
}

void insertionSort(int array[], int length) {
    int j;
    for (j = 1; j < length; j++) {
        int key = array[j];
        int i = j - 1;
        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}
