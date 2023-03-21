/* The following program demonstrates the performance of various
sorting and searching algorithms by measuring the time taken to
execute them on different datasets. */

#include <stdio.h>
#include "algorithms.h"

#define size1 5000 // Size of first dataset
#define size2 100000 // Size of second dataset



int main(){

    int array1[size1], array2[size2];

    // Test sorting algorithms on a dataset of 5000 random numbers in the range [1, 10000]
    printf("Random Numbers: 5000 at [1, 10000]\n\nRunning all sorting algorithms: \n\n");

    // Bubble Sort
    initArray(array1, size1, 1);
    printf("Time taken for bubble sort: %.9f seconds\n", timeCounter1(1, array1, size1));

    // Insertion Sort
    initArray(array1, size1, 1);
    printf("Time taken for insertion sort: %.9f seconds\n", timeCounter1(2, array1, size1));

    // Selection Sort
    initArray(array1, size1, 1);
    printf("Time taken for selection sort: %.9f seconds\n", timeCounter1(3, array1, size1));

    // Merge Sort
    initArray(array1, size1, 1);
    printf("Time taken for merge sort: %.9f seconds\n", timeCounter1(4, array1, size1));

    // Quick Sort
    initArray(array1, size1, 1);
    printf("Time taken for quick sort: %.9f seconds\n", timeCounter1(5, array1, size1));

    // Heap Sort
    initArray(array1, size1, 1);
    printf("Time taken for heap sort: %.9f seconds\n", timeCounter1(6, array1, size1));

    char printIt;

    printf("\nDo you want to print the sorted array? (y/n)\n");
    scanf("%c", &printIt);

    if(printIt == 'y'){
        printArray(array1, size1);
    }

    printf("\n<----------------------------------------------------------------------------------------------------->\n\n");
    // Test searching algorithms on a dataset of 10000 normal distributed numbers
    printf("Normal Distributed Numbers: 100000 - Mean: 50000 - Sigma: 10000\n\nRunning all searching algorithms: \n\n");

    int value1;
    printf("Search for: ");
    scanf("%d", &value1);

    // Measure the time taken for linear search
    initArray(array2, size2, 2);
    printf(" Time taken for linear search: %.9f seconds\n", timeCounter2(1, array2, size2, value1, 1));

    // Measure the time taken for binary search
    initArray(array2, size2, 2);
    printf(" Time taken for binary search: %.9f seconds\n", timeCounter2(2, array2, size2, value1, 1));

    // Measure the time taken for interpolation search
    initArray(array2, size2, 2);
    printf(" Time taken for interpolation search: %.9f seconds\n", timeCounter2(3, array2, size2, value1, 1));

    // Measure the time taken for binary interpolation search (BIS)
    initArray(array2, size2, 2);
    printf(" Time taken for binary interpolation search(BIS): %.9f seconds\n", timeCounter2(4, array2, size2, value1, 1));

    // Measure the time taken for improved binary interpolation search (improved BIS)
    initArray(array2, size2, 2);
    printf(" Time taken for improved binary interpolation search(improved BIS): %.9f seconds\n", timeCounter2(5, array2, size2, value1, 1));

    printf("\n<----------------------------------------------------------------------------------------------------->\n\n");
    // Test searching algorithms on a dataset of 10000 uniformly distributed numbers
    printf("Uniformly Distributed Numbers: 100000 at [1, 100000]\n\nRunning all searching algorithms: \n\n");

    int value2;
    printf("Search for: ");
    scanf("%d", &value2);

    // Measure the time taken for linear search
    initArray(array2, size2, 3);
    printf(" Time taken for linear search: %.9f seconds\n", timeCounter2(1, array2, size2, value2, 1));

    // Measure the time taken for binary search
    initArray(array2, size2, 3);
    printf(" Time taken for binary search: %.9f seconds\n", timeCounter2(2, array2, size2, value2, 1));

    // Measure the time taken for interpolation search
    initArray(array2, size2, 3);
    printf(" Time taken for interpolation search: %.9f seconds\n", timeCounter2(3, array2, size2, value2, 1));

    // Measure the time taken for binary interpolation search (BIS)
    initArray(array2, size2, 3);
    printf(" Time taken for binary interpolation search(BIS): %.9f seconds\n", timeCounter2(4, array2, size2, value2, 1));

    // Measure the time taken for improved binary interpolation search (improved BIS)
    initArray(array2, size2, 3);
    printf(" Time taken for improved binary interpolation search(improved BIS): %.9f seconds\n", timeCounter2(5, array2, size2, value2, 1));

    return 0;
}
