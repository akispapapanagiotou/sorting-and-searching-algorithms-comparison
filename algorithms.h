/* This is a collection of function headers related to sorting and searching algorithms,
as well as utility functions for initializing and printing arrays, and
measuring algorithm performance.*/

void initArray(int *pinakas, int megethos, int dataSet);
void printArray(int *pinakas, int megethos);
double timeCounter1(int algorithmSelection, int *pinakas, int megethos);
double timeCounter2(int algorithmSelection, int *pinakas, int megethos, int value, int printResult);
void swapNumbers(int *number1, int *number2);
void bubbleSort(int *pinakas, int megethos);
void insertionSort(int *pinakas, int megethos);
void selectionSort(int *pinakas, int megethos);
void mergeFunction(int *pinakas, int min, int mid, int max);
void mergeSort(int *pinakas, int min, int max);
void quickSort(int *pinakas, int min, int max);
void heapSort(int *pinakas, int megethos);
void heapify(int *pinakas, int megethos, int i);
int linearSearch(int *pinakas, int megethos, int z);
int binarySearch(int *pinakas, int megethos, int z);
int interpolationSearch(int *pinakas, int megethos, int z);
int binaryInterpolationSearch(int *pinakas, int megethos, int z);
int improvedBinaryInterpolationSearch(int *pinakas, int megethos, int z);

