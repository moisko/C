#include <stdio.h>
#include <stdlib.h>

int **initMatrix(int rows, int columns);

void echoMatrix(int rows, int columns, int **matrix);

void getMaxElementPerRow(int rows, int columns, int **matrix,
		int *maxElementPerRow);

void getMaxElementIndexesPerRow(int rows, int columns, int **matrix,
		int *maxElementIndexesPerRow);

void getMaxElementPerColumn(int rows, int columns, int **matrix,
		int *maxElementPerColumn);

void getMinElementIndexesPerColumn(int rows, int columns, int **matrix,
		int *minElementIndexesPerColumn);

void getPointCols(int rows, int columns, int **matrix);

void swapMatrixRows(int row1, int row2, int **matrix);

void echoArray(int length, int *array);

int main(void) {
	int **matrix, *maxElementPerRow, *maxElementPerColumn, rows, columns;

	scanf("%d", &rows);
	scanf("%d", &columns);
	matrix = initMatrix(rows, columns);
	printf("Matrix\n");
	echoMatrix(rows, columns, matrix);

	maxElementPerRow = (int *) malloc(rows * sizeof(int));
	getMaxElementPerRow(rows, columns, matrix, maxElementPerRow);
	printf("Max elements per row\n");
	echoArray(rows, maxElementPerRow);

	maxElementPerColumn = (int *) malloc(columns * sizeof(int));
	getMaxElementPerColumn(rows, columns, matrix, maxElementPerColumn);
	printf("Max elements per column\n");
	echoArray(columns, maxElementPerColumn);

	getPointCols(rows, columns, matrix);

	int row1, row2;
	scanf("%d", &row1);
	scanf("%d", &row2);
	swapMatrixRows(row1, row2, matrix);
	printf("Swapped rows\n");
	echoMatrix(rows, columns, matrix);

	free(matrix);
	free(maxElementPerRow);
	free(maxElementPerColumn);

	return EXIT_SUCCESS;
}

void swapMatrixRows(int row1, int row2, int **matrix) {
	int *temp;
	temp = matrix[row1];
	matrix[row1] = matrix[row2];
	matrix[row2] = temp;
}

int **initMatrix(int rows, int columns) {
	int **matrix, row, column;
	matrix = (int **) malloc(rows * sizeof(int *));
	for (row = 0; row < rows; row++)
		matrix[row] = (int *) malloc(columns * sizeof(int));

	for (row = 0; row < rows; row++) {
		for (column = 0; column < columns; column++) {
			scanf("%d", (matrix[row] + column));
		}
	}

	return matrix;
}

void echoMatrix(int rows, int columns, int **matrix) {
	int row, column;
	for (row = 0; row < rows; row++) {
		for (column = 0; column < columns; column++)
			printf("%3d", *(matrix[row] + column));
		printf("\n");
	}
}

void echoArray(int length, int *array) {
	int i;
	for (i = 0; i < length; i++)
		printf("%3d", array[i]);
	printf("\n");
}

/**
 * For more information about how this function should be implemented, read ExerciceV/p.4 from TP
 */
void getPointCols(int rows, int columns, int **matrix) {
	printf("Max element indexes per row\n");
	int *maxElementIndexesPerRow = (int *) malloc(rows * sizeof(int));
	getMaxElementIndexesPerRow(rows, columns, matrix, maxElementIndexesPerRow);
	echoArray(rows, maxElementIndexesPerRow);

	printf("Min element indexes per column\n");
	int *minElementIndexesPerColumn = (int *) malloc(columns * sizeof(int));
	getMinElementIndexesPerColumn(rows, columns, matrix,
			minElementIndexesPerColumn);
	echoArray(columns, minElementIndexesPerColumn);

	//TODO finish the implementation

	// free memory
	free(maxElementIndexesPerRow);
	free(minElementIndexesPerColumn);
}

void getMaxElementPerRow(int rows, int columns, int **matrix,
		int *maxElementPerRow) {
	int i, j;
	for (i = 0; i < rows; i++, maxElementPerRow++) {
		*maxElementPerRow = *matrix[i];
		for (j = 0; j < columns; j++)
			if (*(matrix[i] + j) > *maxElementPerRow)
				*maxElementPerRow = *(matrix[i] + j);
	}
}

void getMaxElementIndexesPerRow(int rows, int columns, int **matrix,
		int *maxElementIndexesPerRow) {
	int i, j;
	for (i = 0; i < rows; i++, maxElementIndexesPerRow++) {
		int maxElementPerRow = *matrix[i];
		int maxElementIndexPerRow = 0;
		for (j = 1; j < columns; j++) {
			int currentRowElement = *(matrix[i] + j);
			if (currentRowElement > maxElementPerRow) {
				maxElementPerRow = currentRowElement;
				maxElementIndexPerRow = j;
			}
		}
		*maxElementIndexesPerRow = maxElementIndexPerRow;
	}
}

void getMinElementIndexesPerColumn(int rows, int columns, int **matrix,
		int *minElementIndexesPerColumn) {
	int i, j;
	for (j = 0; j < columns; j++, minElementIndexesPerColumn++) {
		int minElementPerColumn = *(matrix[0] + j);
		int minElementIndexPerColumn = 0;
		for (i = 1; i < rows; i++) {
			int currentColumnElement = *(matrix[i] + j);
			if (currentColumnElement < minElementPerColumn) {
				minElementPerColumn = currentColumnElement;
				minElementIndexPerColumn = i;
			}
		}
		*minElementIndexesPerColumn = minElementIndexPerColumn;
	}
}

void getMaxElementPerColumn(int rows, int columns, int **matrix,
		int *maxElementPerColumn) {
	int i, j;
	for (j = 0; j < columns; j++, maxElementPerColumn++) {
		int maxColumnElement = *(matrix[0] + j);
		for (i = 1; i < rows; i++) {
			int currentColumnElement = *(matrix[i] + j);
			if (currentColumnElement > maxColumnElement) {
				maxColumnElement = currentColumnElement;
			}
		}
		*maxElementPerColumn = maxColumnElement;
	}
}
