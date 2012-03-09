#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(void) {
    int t[ARRAY_SIZE];

    /* Set array length */
    int length = initArray(t, ARRAY_SIZE);
    printf("Length of array t=%d\n", length);

    /* Echo array t */
    printf("Array t :\n");
    printArray(t, length);

    /* Sort array t */
    insertionSort(t, length);
    printf("Sorted t:\n");
    printArray(t, length);

    /* Echo max element in array t */
    printf("Max element: %d\n", t[length - 1]);

    /* Echo number of positive elements in array t */
    int tPosLength = getNumberOfPosElements(t, length);
    printf("Number of positive elements: %d\n", tPosLength);
    int tpos[tPosLength];
    copyPosElements(t, length, tpos, tPosLength);
    printArray(tpos, tPosLength);


    int tNegLength = getNumberOfNegElements(t, length);
    printf("Number of negative elements: %d\n", tNegLength);
    int tneg[tNegLength];
    copyNegElements(t, length, tneg, tNegLength);
    printArray(tneg, tNegLength);
    
    int arr[] = {5,6,4,7,3};
    int maxElement = getMaxElementWithEvenIndex(arr, 1, 3);
    printf("Max element with even index: %d\n", maxElement);

    return EXIT_SUCCESS;
}
