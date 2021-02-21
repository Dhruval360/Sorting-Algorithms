// This file contains all the function prototypes
#include <stdio.h>
//#define loop // This enables counting of loop condition comparisons as well

// Quick sort
int partition(int a[], int low, int high, unsigned long *comparisons);
void quickSort(int a[], int low, int high, unsigned long *comparisons);

// Merge sort
int *auxilliary;
void merge(int a[], unsigned int low, unsigned int mid, unsigned int high, unsigned long *comparisons);
void mergeSort(int a[], unsigned int low, unsigned int high, unsigned long *comparisons);

// Selection sort
void selectionSort(int array[], unsigned int n, unsigned long *comparisons);

// Bubble sort
void bubbleSort(int array[], unsigned int n, unsigned long *comparisons);

// Testing
void test(int a[], unsigned int n, char *sort_name);