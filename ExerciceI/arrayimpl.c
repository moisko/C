#include <stdio.h>
#include <stdbool.h>
#include "array.h"

void insertionSort(int t[], int length) {
    int j;
    for (j = 1; j < length; j++) {
        int key = t[j];
        int i = j - 1;
        while (i >= 0 && t[i] > key) {
            t[i + 1] = t[i];
            i = i - 1;
        }
        t[i + 1] = key;
    }
}

void mergeSort(int t[], int length) {
    // provide implementation

}

void heapSort(int t[], int length) {
    // provide implementation

}

void quickSort(int t[], int length) {
    // provide implementation

}

void copyPosElements(int t[], int length, int tpos[], int tPosLength) {
    int i, j = 0;
    while (j < tPosLength) {
        for (i = 0; i < length; i++) {
            if (t[i] > 0) {
                tpos[j] = t[i];
                j++;
            }
        }
    }
}

int getNumberOfPosElements(int t[], int length) {
    int i, numberOfPosElements = 0;
    for (i = 0; i < length; i++) {
        if (t[i] > 0) {
            numberOfPosElements++;
        }
    }

    return numberOfPosElements;
}

void copyNegElements(int t[], int length, int tneg[], int tNegLength) {
    int i, j = 0;
    while (j < tNegLength) {
        for (i = 0; i < length; i++) {
            if (t[i] < 0) {
                tneg[j] = t[i];
                j++;
            }
        }
    }
}

int getNumberOfNegElements(int t[], int length) {
    int i, numberOfNegElements = 0;
    for (i = 0; i < length; i++) {
        if (t[i] < 0) {
            numberOfNegElements++;
        }
    }

    return numberOfNegElements;
}

int getMaxElementWithEvenIndex(int t[], int l, int r) {
    int i;
    int maxElementWithEvenIndex = getFirstElementWithEvenIndex(l, r);
    for (i = l; i < r; i++) {
        if (isIndexEven(i)) {
            if (maxElementWithEvenIndex < t[i]) {
                maxElementWithEvenIndex = t[i];
            }
        }
    }

    return maxElementWithEvenIndex;
}

int getMaxElementIndex(int t[], int length) {
    int maxElement = t[0];
    int maxElementIndex = 0;
    int i;
    for (i = 1; i < length; i++) {
        if (maxElement < t[i]) {
            maxElementIndex = i;
        }
    }

    return maxElementIndex;
}

int getFirstElementWithEvenIndex(int l, int r) {
    int i, firstEvenIndex = -1;
    int length = r - l + 1;
    for (i = 0; i < length; i++) {
        if (isIndexEven(i)) {
            firstEvenIndex = i;
            break;
        }
    }

    return firstEvenIndex;
}

bool isIndexEven(int index) {
    if (index % 2 == 0) {
        return true;
    } else return false;
}

void printArray(int t[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("t[%d]=%d ", i, t[i]);
    }
    printf("\n");
}

int initArray(int t[], int length) {
    int n = 0, temp;
    while (n < length) {
        scanf("%d", &temp);
        t[n] = temp;
        n++;
    }
    return n;
}
