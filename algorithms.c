/* This is a collection of functions related to sorting and searching algorithms,
as well as utility functions for initializing and printing arrays, and
measuring algorithm performance.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <windows.h>
#include "algorithms.h"



/* This function reads integer values from a file that contains data sets
and initializes an integer array with those values. The data set is
selected based on the input parameter "dataSet", which corresponds to
a specific file. If the file fails to open, the program will exit with
an error message.*/
void initArray(int *pinakas, int megethos, int dataSet){

    FILE *fp = NULL;

    switch(dataSet){
        case 1:
            fp = fopen("dataSetRandom.txt", "r");
            break;

        case 2:
            fp = fopen("dataSetNormal.txt", "r");
            break;

        case 3:
            fp = fopen("dataSetUniform.txt", "r");
            break;

        default:
            printf("Default case of timeCounter1 function.\n");
            break;
    }

    if(fp == NULL){
        printf("ERROR: Data set wasn't opened. Exiting...\n");
        exit(0);
    }

    int i;
    for(i=0; i<megethos; i++){
        fscanf(fp, "%d", &pinakas[i]);
    }

    if(fp != NULL){
        fclose(fp);
    }

}



/* This function prints the elements of an integer array to the console.
The elements are separated by commas and enclosed in square brackets.*/
void printArray(int *pinakas, int megethos){

    int i;
    printf("Elements of array: \n[");
    for(i=0; i<megethos-1; i++){
        printf("%d, ", pinakas[i]);
    }
    printf("%d]\n\n", pinakas[megethos-1]);
}



/* This function measures the execution time of a sorting algorithm selected by
the input parameter "algorithmSelection" on an integer array of size "megethos".
It uses the Windows API's QueryPerformanceCounter() function to measure the start
and end times of the algorithm's execution, calculates the elapsed time, and returns
it in seconds as a double value. If the input parameter is not within the range of
available sorting algorithms, the function prints a default case message.*/
double timeCounter1(int algorithmSelection, int *pinakas, int megethos){

    LARGE_INTEGER startingTime, endingTime, timeSpent, frequency;

    QueryPerformanceFrequency(&frequency);

    switch(algorithmSelection){
        case 1:
            QueryPerformanceCounter(&startingTime);
            bubbleSort(pinakas, megethos);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 2:
            QueryPerformanceCounter(&startingTime);
            insertionSort(pinakas, megethos);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 3:
            QueryPerformanceCounter(&startingTime);
            selectionSort(pinakas, megethos);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 4:
            QueryPerformanceCounter(&startingTime);
            mergeSort(pinakas, 0, megethos-1);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 5:
            QueryPerformanceCounter(&startingTime);
            quickSort(pinakas, 0, megethos-1);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        case 6:
            QueryPerformanceCounter(&startingTime);
            heapSort(pinakas, megethos);
            QueryPerformanceCounter(&endingTime);
            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;
            break;

        default:
            printf("Default case of timeCounter function.\n");
            break;
    }

    return (double)timeSpent.QuadPart/1000000000;
}



/* This is a function that measures the execution time of different searching algorithms on an
integer array, given the selected algorithm, array, array size, search value, and whether or not
to print the result. The function uses the QueryPerformanceCounter function to obtain
high-resolution performance counter values, and then calculates the time spent using the frequency
of the performance counter. The function returns the execution time in seconds as a double.*/
double timeCounter2(int algorithmSelection, int *pinakas, int megethos, int value, int printResult){

    int res;
    LARGE_INTEGER startingTime, endingTime, timeSpent, frequency;

    QueryPerformanceFrequency(&frequency);

    switch(algorithmSelection){
        case 1:
            QueryPerformanceCounter(&startingTime);
            res=linearSearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        case 2:
            heapSort(pinakas, megethos);

            QueryPerformanceCounter(&startingTime);
            res=binarySearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        case 3:
            heapSort(pinakas, megethos);

            QueryPerformanceCounter(&startingTime);
            res=interpolationSearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        case 4:
            heapSort(pinakas, megethos);

            QueryPerformanceCounter(&startingTime);
            res=binaryInterpolationSearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        case 5:
            heapSort(pinakas, megethos);

            QueryPerformanceCounter(&startingTime);
            res=improvedBinaryInterpolationSearch(pinakas, megethos, value);
            QueryPerformanceCounter(&endingTime);

            timeSpent.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
            timeSpent.QuadPart *= 1000000000;
            timeSpent.QuadPart /= frequency.QuadPart;

            if(printResult==1){
                if(res==-1)
                    printf("Value %d was not found.", value);
                else
                    printf("Value %d was found at location %d.", value, res);
            }
            break;

        default:
            printf("Default case of timeCounter2 function.\n");
            break;
    }

    return (double)timeSpent.QuadPart/1000000000;
}



/* This function swaps the values of two integer variables by using pointers
to the variables.*/
void swapNumbers(int *number1, int *number2){
    int temp;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}



/* This function implements the bubble sort algorithm to sort an array of integers
in ascending order.*/
void bubbleSort(int *pinakas, int megethos){

    int toDo, index, didSwap=1;

    for(toDo=megethos-1; toDo>0; toDo--){
        didSwap=0;
        for(index=0; index<toDo; index++){
            if(pinakas[index]>pinakas[index+1]){
                swapNumbers(&pinakas[index], &pinakas[index+1]);
                didSwap=1;
            }
        }
        if(didSwap==0){
            break;
        }
    }
}



/* This function sorts an array of integers in ascending order using the
insertion sort algorithm.*/
void insertionSort(int *pinakas, int megethos){

    int i, j, temp;

    for(i=1; i<megethos; i++){
        temp=pinakas[i];

        for(j=i-1; j>=0 && temp<pinakas[j]; j--){
            pinakas[j+1]=pinakas[j];
        }
        pinakas[j+1]=temp;
    }
}



/* This function sorts an array of integers using selection
sort algorithm, by iterating over the array and finding the minimum element
in the unsorted part of the array and swapping it with the first
element of the unsorted part.*/
void selectionSort(int *pinakas, int megethos){

    int i, j, min;
    for(i=0; i<megethos-1; i++){
        min=i;

        for(j=i+1; j<megethos; j++){
            if(pinakas[j]<pinakas[min]){
                min=j;
            }
        }

        if(min!=i){
            swapNumbers(&pinakas[min], &pinakas[i]);
        }
    }
}



/* This function merges two sorted sub-arrays of an integer array
into a single sorted array. It uses a temporary array to store
the merged array.*/
void mergeFunction(int *pinakas, int min, int mid, int max){

    int i, j, k;
    int size=max+1;
    int tempArray[size];

    j=min;
    k=mid+1;

    for(i=min; j<=mid && k<=max; i++){
        if(pinakas[j]<=pinakas[k]){
            tempArray[i]=pinakas[j];
            j++;
        }
        else{
            tempArray[i]=pinakas[k];
            k++;
        }
    }

    if(j>mid){
        while(k<=max){
            tempArray[i]=pinakas[k];
            k++;
            i++;
        }
    }
    else{
        while(j<=mid){
            tempArray[i]=pinakas[j];
            j++;
            i++;
        }
    }

    for(i=min; i<size; i++){
        pinakas[i]=tempArray[i];
    }
}



/* This function sorts an integer array in ascending order using the
merge sort algorithm.*/
void mergeSort(int *pinakas, int min, int max){

    int mid;

    if(min<max){
        mid=(min+max)/2;

        mergeSort(pinakas, min, mid);

        mergeSort(pinakas, mid+1, max);

        mergeFunction(pinakas, min, mid, max);
    }
}



/* This function implements the quicksort algorithm to sort an array of
integers in ascending order.*/
void quickSort(int *pinakas, int min, int max){

    int pivot, leftArrow, rightArrow;

    leftArrow=min;
    rightArrow=max;
    pivot=pinakas[(min+max)/2];

    do{
        while(pinakas[rightArrow]>pivot){
            rightArrow--;
        }
        while(pinakas[leftArrow]<pivot){
            leftArrow++;
        }
        if(leftArrow<=rightArrow){
            swapNumbers(&pinakas[leftArrow], &pinakas[rightArrow]);
            leftArrow++;
            rightArrow--;
        }
    }
    while(rightArrow>=leftArrow);

    if(min<rightArrow){
        quickSort(pinakas, min, rightArrow);
    }

    if(leftArrow<max){
        quickSort(pinakas, leftArrow, max);
    }
}



/* This function performs a heap sort on an integer
array.*/
void heapSort(int *pinakas, int megethos){

    int i;
    for(i=megethos/2-1; i>=0; i--){
        heapify(pinakas, megethos, i);
    }

    for(i=megethos-1; i>=0; i--){
        swapNumbers(&pinakas[0], &pinakas[i]);
        heapify(pinakas, i, 0);
    }
}



/* This function is used in heap sort to build a max-heap from an
array by recursively heapifying each sub-tree.*/
void heapify(int *pinakas, int megethos, int i){

    int max=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<megethos && pinakas[left]>pinakas[max]){
        max=left;
    }

    if(right<megethos && pinakas[right]>pinakas[max]){
        max=right;
    }

    if(max!=i){
        swapNumbers(&pinakas[i], &pinakas[max]);
        heapify(pinakas, megethos, max);
    }
}



/* This function performs linear search on an array to find the
index of a given element, and returns -1 if the element
is not found in the array.*/
int linearSearch(int *pinakas, int megethos, int z){

    int i;
    for(i=0; i<megethos; i++){
        if(pinakas[i]==z){
            return i;
        }
    }
    return -1;
}



/* This function implements binary search algorithm to search for a
specific value 'z' in an array of size 'megethos'.*/
int binarySearch(int *pinakas, int megethos, int z){

    int start, mid, end;

    start=0;
    end=megethos-1;
    mid=(start+end)/2;

    while(start<=end && z>=pinakas[start] && z<=pinakas[end]){

        if(z==pinakas[mid]){
            return mid;
        }
        else if(z<pinakas[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }

        mid=(start+end)/2;
    }

    return -1;
}



/* This function implements interpolation search, which is a variant of binary search. */
int interpolationSearch(int *pinakas, int megethos, int z){
    int start = 0;
    int end = (megethos - 1);

    while (start <= end && z >= pinakas[start] && z <= pinakas[end]){
        if (start == end){
            if (pinakas[start] == z)
                return start;
            return -1;
        }

        int next = start + (((double)(end-start) / (pinakas[end]-pinakas[start]))*(z - pinakas[start]));

        if (pinakas[next] == z)
            return next;

        if (pinakas[next] < z)
            start = next + 1;

        else
            end = next - 1;
    }
    return -1;
}



/* This function implements the binary interpolation search algorithm to search for an
integer value z in a sorted integer array.*/
int binaryInterpolationSearch(int *pinakas, int megethos, int z){

    int start, end, next, biggerTemp, smallerTemp;
    int size = megethos;

    start = 0;
    end = size-1;
    size = end-start+1;

    if (z == 0){
        next = 0;
    }
    else{
        next = (int)(size*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start])) + 1);
    }

    if(next > end ){
        next = end;
    }
    if(next < start ){
        next = start;
    }

    if(z<pinakas[start] || z>pinakas[end]){
        return -1;
    }

    while(z!=pinakas[next]){

        int i=0;
        size=end-start;

        if(size<=3){
            int j;
            for(j=start; j<=end; j++){
                if(z==pinakas[j]){
                    return j;
                }
            }
            return -1;
        }

        if(z>=pinakas[next]){
            while(z>pinakas[(int)((next+(i*(sqrt(size))))-1)]){
                i++;

                biggerTemp = (int)((next+(i*(sqrt(size))))-1);
                if(biggerTemp > end ){
                        i--;
                        break;
                }
            }

            if ((int)(next+(i*(sqrt(size)))) <= end)
                end=(int)(next+(i*(sqrt(size))));

            if ( (int)(next+((i-1)*(sqrt(size)))) >= start)
                start=(int)(next+((i-1)*(sqrt(size))));

            if(biggerTemp>end)
                end = megethos-1;

            if(biggerTemp<0)
                start = 0;

        }
        else if(z<pinakas[next]){
            while(z<pinakas[(int)(next-(i*(sqrt(size)))+1)]){
                i++;

                smallerTemp = (int)(next-(i*(sqrt(size)))+1);
                if(smallerTemp > end ){
                        i--;
                        break;
                }
            }

            if( (int)(next-((i-1)*(sqrt(size)))) <= end)
                end=(int)(next-((i-1)*(sqrt(size))));

            if ( (int)(next-(i*(sqrt(size)))) >= start )
                start=(int)(next-(i*(sqrt(size))));

            if(smallerTemp>end)
                end = megethos-1;

            if(smallerTemp<0)
                start = 0;

        }


        if(pinakas[end]-pinakas[start] == 0)
            next = (int)(start + ((end-start+1)*(double)(z-pinakas[start])) - 1);
        else{

        next = (int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1);

        if ((int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1) > end)
            next = end;
        if ((int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1) < start )
            next = start;
        }
    }

    if(z==pinakas[next]){
        return next;
    }
    else{
        return -1;
    }
}



/* This function implements an improved version of the binary interpolation search
algorithm to find the index of a given element in a sorted array. It uses interpolation
to guess the approximate location of the element, and then adjusts the search range
based on whether the element is bigger or smaller than the guess. The function also
includes some optimizations, such as doubling the step size when the element is not
found, and checking for edge cases where the guess may be outside the range of the
array. The function returns the index of the element if found, or -1 if not found.*/
int improvedBinaryInterpolationSearch(int *pinakas, int megethos, int z){
    int start, end, next;
    int biggerTemp;
    int smallerTemp;
    int size = megethos;
    int i=1;
    start = 0;
    end = size-1;
    size = end-start+1;


    if (z == 0){
        next = 0;
    }
    else{
        next = (int)(size*(double)((z-pinakas[start]) / (pinakas[end]-pinakas[start])) + 1);
    }
    if( (int)(size*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start])) + 1) > end ){
        next = end;
    }
    if( (int)(size*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start])) + 1) < start ){
        next = start;
    }
    if(z<pinakas[start] || z>pinakas[end]){
        return -1;
    }

    int sizeAfter = -1;

    while(z!=pinakas[next]){
        i=1;
        size=end-start-1;


        if(size<=3 || (size >= sizeAfter && size>=0)){
            for(int j=start; j<=end; j++){
                if(z==pinakas[j]){
                    return j;
                }
            }
            return -1;
        }

        sizeAfter = size;

        if(z>=pinakas[next]){
            while(z>pinakas[(int)((next+(i*(sqrt(size))))-1)]){
                i=i*2;
                biggerTemp = (int)((next+(i*(sqrt(size))))-1);
                if(biggerTemp > end ){
                        i=i/2;
                        break;
                }
            }


            if ((int)(next+(i*(sqrt(size)))) <= end)
                end=(int)(next+(i*(sqrt(size))));

            if ( (int)(next+((i-1)*(sqrt(size)))) >= start)
                start=(int)(next+((i-1)*(sqrt(size))));


            if(biggerTemp>end)
                end = megethos-1;

            if(biggerTemp<0)
                start = 0;


        }
        else if(z<pinakas[next]){
            while(z<pinakas[(int)(next-(i*(sqrt(size)))+1)]){
                i=i*2;
                smallerTemp = (int)(next-(i*(sqrt(size)))+1);
                if(smallerTemp > end ){
                        i=i/2;
                        break;
                }
            }


            if( (int)(next-((i-1)*(sqrt(size)))) <= end)
                end=(int)(next-((i-1)*(sqrt(size))));

            if ( (int)(next-(i*(sqrt(size)))) >= start )
                start=(int)(next-(i*(sqrt(size))));

            if(smallerTemp>end)
                end = megethos-1;

            if(smallerTemp<0)
                start = 0;


        }


        if(pinakas[end]-pinakas[start] == 0){
            next = (int)(start + ((end-start+1)*(double)(z-pinakas[start])) - 1);
        }
        else{

            next = (int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1);

            if ((int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1) > end){
                next = end;

            }
            if ((int)(start + ((end-start+1)*(double)((z-pinakas[start])/(pinakas[end]-pinakas[start]))) - 1) < start ){
                next = start;
            }
        }

    }
    if(z==pinakas[next]){
        return next;
    }
    else{
        return -1;
    }
}

