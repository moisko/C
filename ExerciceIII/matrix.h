#ifndef MATRIX_H
#define	MATRIX_H

#ifdef	__cplusplus
extern "C" {
#endif

    int **initMatrix(int matrixRows, int matrixColumns);

    void printMatrix(int **matrix, int matrixRows, int matrixColumns);
    
    int **insertMatrixRow(int **matrix, int matrixRows, int matrixColumns, int *matrixRowToInsert);

    int *calculateSumOfMatrixColumns(int **matrix, int matrixRows, int matrixColumns);

    void freeMatrix(int **matrix, int matrixRows);

    void getMinElementsPerColumn(int **matrix, int matrixRows, int matrixColumns, int *minElementsPerColumn);

#ifdef	__cplusplus
}
#endif

#endif	/* MATRIX_H */

