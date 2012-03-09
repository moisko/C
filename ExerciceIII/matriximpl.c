#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int **initMatrix(int matrixRows, int matrixColumns) {
	int **matrix, matrixRow, matrixColumn;
	matrix = (int **) malloc(matrixRows * sizeof(int *));
	for (matrixRow = 0; matrixRow < matrixRows; matrixRow++) {
		matrix[matrixRow] = (int *) malloc(matrixColumns * sizeof(int));
	}

	for (matrixRow = 0; matrixRow < matrixRows; matrixRow++) {
		for (matrixColumn = 0; matrixColumn < matrixColumns; matrixColumn++) {
			scanf(
					"%d",
					((int *) matrix + (matrixRow * matrixColumns) + matrixColumn));
		}
	}

	return matrix;
}

void printMatrix(int **matrix, int matrixRows, int matrixColumns) {
	int matrixRow, matrixColumn;
	for (matrixRow = 0; matrixRow < matrixRows; matrixRow++) {
		for (matrixColumn = 0; matrixColumn < matrixColumns; matrixColumn++) {
			printf(
					"%d\t",
					*((int *) matrix + (matrixRow * matrixColumns)
							+ matrixColumn));
		}
		printf("\n");
	}
}

int *calculateSumOfMatrixColumns(int **matrix, int matrixRows,
		int matrixColumns) {
	int matrixRow, matrixColumn, *sumOfMatrixColumns;

	sumOfMatrixColumns = (int *) calloc(matrixColumns, sizeof(int));
	if (sumOfMatrixColumns == NULL) {
		printf("Allocation error - calculateSumOfMatrixColumns()!\n");
		exit(1);
	}

	int columnSum = 0;
	for (matrixColumn = 0; matrixColumn < matrixColumns; matrixColumn++) {
		for (matrixRow = 0; matrixRow < matrixRows; matrixRow++) {
			columnSum += *((int *) matrix + (matrixRow * matrixColumns)
					+ matrixColumn);
		}
		sumOfMatrixColumns[matrixColumn] = columnSum;
		columnSum = 0;
	}

	// free(sumOfMatrixColumns);

	return sumOfMatrixColumns;
}

void getMinElementsPerColumn(int **matrix, int matrixRows, int matrixColumns,
		int *minElementsPerColumn) {
	int i, j;

	// minElementsPerColumn = (int *) malloc(matrixColumns * sizeof(int));
	if (minElementsPerColumn == NULL) {
		printf("Allocation error - calculateSumOfMatrixColumns()!\n");
		exit(1);
	}

	int minElementPerColumn;
	for (j = 0; j < matrixColumns; j++) {
		// minElementPerColumn = *(matrix[0] + j);
		minElementPerColumn = *((int *) matrix + j);
		for (i = 1; i < matrixRows; i++) {
			int currentColumnElement = *((int *) matrix + (i * matrixColumns)
					+ j);
			if (currentColumnElement < minElementPerColumn) {
				minElementPerColumn = currentColumnElement;
			}
		}
		minElementsPerColumn[j] = minElementPerColumn;
	}

	// return minElementsPerColumn;
}

int **insertMatrixRow(int **matrix, int matrixRows, int matrixColumns,
		int *matrixRowToInsert) {
	matrixRows++;
	matrix = (int **) realloc((int **) matrix, matrixRows);
	if (!matrix) {
		printf("Allocation error - insertMatrixRow()!\n");
		exit(1);
	}

	// Insert matrixRowToInsert as last row in matrix
	int matrixRow, matrixColumn;
	for (matrixRow = 0; matrixRow < matrixRows; matrixRow++) {
		for (matrixColumn = 0; matrixColumn < matrixColumns; matrixColumn++) {
			if (matrixRow == (matrixRows - 1)) {
				int value = *(matrixRowToInsert + matrixColumn);
				*((int *) matrix + (matrixRow * matrixColumns) + matrixColumn) =
						value;
			}
		}
	}

	return matrix;
}

void freeMatrix(int **matrix, int matrixRows) {
	int i;
	for (i = 0; i < matrixRows; i++) {
		free(matrix[i]);
		matrix[i] = NULL;
	}
	// free(matrix);
	matrix = NULL;
}
