#ifndef ARRAY_H
#define	ARRAY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#define ARRAY_SIZE 5

    int initArray(int t[], int length);

    void insertionSort(int t[], int length);

    void mergeSort(int t[], int length);

    /* Use max-heaps for the heapsort algorithm. 
     * 
     * Viewing the heap as a tree, we define a height of a node in a heap to be
     * the number of edges on the longest simple downwad path from the node to 
     * a leaf, and we define the height of the heap to be the height of its 
     * root.
     * 
     * A heap of n elements is based on a complete binary tree, its height is 
     * lg(n). 
     * 
     * The basic operations on heaps run in time at most proportional to the 
     * height of the tree and thus take O(lg(n)) time. 
     * 
     * Basic procedures used in sorting algorithm and priority queue data 
     * structure:
     * 
     * -> MAX-HEAPIFY - runs in O(lg(n)) time is the key to maintain the 
     * max-heap property
     * -> BUILD-MAX-HEAP - procedure which runs in linear time, produces a max
     * heap from an unordered input array
     * -> HEAPSORT - procedure which runs in O(nlg(n)) time, sorts an array in 
     * place
     * -> MAX-HEAP-INSERT, HEAP-EXTRACT-MAX, HEAP-INCREASE-KEY and HEAP-MAXIMUM
     * procedures, which run in O(lgn) time, allow the heap data structure to 
     * implement a priority queue.
     */
    void heapSort(int t[], int length);

    void quickSort(int t[], int length);

    int getNumberOfPosElements(int t[], int length);

    void copyPosElements(int t[], int length, int tpos[], int tPosLength);

    int getNumberOfNegElements(int t[], int length);

    void copyNegElements(int t[], int length, int tneg[], int tNegLength);

    int getMaxElementIndex(int t[], int length);

    int getMaxElementWithEvenIndex(int t[], int l, int r);
    
    int getFirstElementWithEvenIndex(int l, int r);

    bool isIndexEven(int index);

    void printArray(int t[], int length);

#ifdef	__cplusplus
}
#endif

#endif	/* ARRAY_H */

