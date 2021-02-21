/*
 This is the driver code used to compare the performance of:
    1) Merge sort
    2) Quick sort
    3) Selection sort
    4) Bubble sort
*/

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"

#define MAX 19
#define base 100000 // This is the starting number of elements (100k over here)
#define step 50000  // This is the increment step (50k over here)

#define merge 0
#define quick 1
#define selection 2
#define bubble 3

int main(){
    unsigned int sizes[MAX] = {base}; // This array contains the various input sizes used for the analysis
    for(unsigned int i = 1; i < MAX; i++) sizes[i] = sizes[i-1] + step;

    unsigned long comparisons[4] = {0}; // Used to count the number of comparisons in each algorithm
    clock_t start, end;
    double time;
    #ifdef loop
    FILE *mergeTime = fopen("Analytics/MergeSort/Including-Loop-Comparisons/Timing.csv", "w");
    FILE *quickTime = fopen("Analytics/QuickSort/Including-Loop-Comparisons/Timing.csv", "w");
    FILE *selectionTime = fopen("Analytics/SelectionSort/Including-Loop-Comparisons/Timing.csv", "w");
    FILE *bubbleTime = fopen("Analytics/BubbleSort/Including-Loop-Comparisons/Timing.csv", "w");

    FILE *mergeComparisons = fopen("Analytics/MergeSort/Including-Loop-Comparisons/Comparisons.csv", "w");
    FILE *quickComparisons = fopen("Analytics/QuickSort/Including-Loop-Comparisons/Comparisons.csv", "w");
    FILE *selectionComparisons = fopen("Analytics/SelectionSort/Including-Loop-Comparisons/Comparisons.csv", "w");
    FILE *bubbleComparisons = fopen("Analytics/BubbleSort/Including-Loop-Comparisons/Comparisons.csv", "w");
    #endif

    #ifndef loop
    FILE *mergeTime = fopen("Analytics/MergeSort/Element-to-Element-Comparisons-Only/Timing.csv", "w");
    FILE *quickTime = fopen("Analytics/QuickSort/Element-to-Element-Comparisons-Only/Timing.csv", "w");
    FILE *selectionTime = fopen("Analytics/SelectionSort/Element-to-Element-Comparisons-Only/Timing.csv", "w");
    FILE *bubbleTime = fopen("Analytics/BubbleSort/Element-to-Element-Comparisons-Only/Timing.csv", "w");

    FILE *mergeComparisons = fopen("Analytics/MergeSort/Element-to-Element-Comparisons-Only/Comparisons.csv", "w");
    FILE *quickComparisons = fopen("Analytics/QuickSort/Element-to-Element-Comparisons-Only/Comparisons.csv", "w");
    FILE *selectionComparisons = fopen("Analytics/SelectionSort/Element-to-Element-Comparisons-Only/Comparisons.csv", "w");
    FILE *bubbleComparisons = fopen("Analytics/BubbleSort/Element-to-Element-Comparisons-Only/Comparisons.csv", "w");
    #endif
    
    fprintf(mergeComparisons, "%s\n", "Number of elements, Number of comparisons");
    fprintf(quickComparisons, "%s\n", "Number of elements, Number of comparisons");
    fprintf(selectionComparisons, "%s\n", "Number of elements, Number of comparisons");
    fprintf(bubbleComparisons, "%s\n", "Number of elements, Number of comparisons");
    
    fprintf(mergeTime, "%s\n", "Number of elements, Time taken (seconds)");
    fprintf(quickTime, "%s\n", "Number of elements, Time taken (seconds)");
    fprintf(selectionTime, "%s\n", "Number of elements, Time taken (seconds)");
    fprintf(bubbleTime, "%s\n", "Number of elements, Time taken (seconds)");

    int *array = (int*)malloc(sizeof(int)*sizes[MAX-1]);
    int *input = (int*)malloc(sizeof(int)*sizes[MAX-1]);
    auxilliary = (int*)malloc(sizeof(int)*sizes[MAX-1]); // Used by merge sort

    for(unsigned i = 0; i < sizeof(sizes)/sizeof(unsigned int); i++){
        printf("Input size %u\n", sizes[i]);
        for(unsigned j = 0; j < sizes[i]; j++) array[j] = rand(); // Generating an array of random numbers

///////////////////////////////////////////////////////// Merge sort /////////////////////////////////////////////////////////
        printf("\tMerge sort     - ");
        memcpy(input, array, sizes[i]*sizeof(int));
        comparisons[merge] = 0;

        start = clock();
        mergeSort(input, 0, sizes[i], &comparisons[merge]);
        end = clock();
        
        test(input, sizes[i], "Merge Sort");
        time = ((double)(end - start))/CLOCKS_PER_SEC;
        fprintf(mergeTime, "%u, %lf\n", sizes[i], time);
        fprintf(mergeComparisons, "%u, %lu\n", sizes[i], comparisons[merge]);
        printf("Completed in %lf seconds\n", time);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////// Quick sort /////////////////////////////////////////////////////////
        printf("\tQuick sort     - ");
        memcpy(input, array, sizes[i]*sizeof(int));
        comparisons[quick] = 0;

        start = clock();
        quickSort(input, 0, sizes[i], &comparisons[quick]);
        end = clock();
        
        test(input, sizes[i], "Quick Sort");
        time = ((double)(end - start))/CLOCKS_PER_SEC;
        fprintf(quickTime, "%u, %lf\n", sizes[i], time);
        fprintf(quickComparisons, "%u, %lu\n", sizes[i], comparisons[quick]);
        printf("Completed in %lf seconds\n", time);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

/////////////////////////////////////////////////////// Selection sort ///////////////////////////////////////////////////////
        printf("\tSelection sort - ");
        memcpy(input, array, sizes[i]*sizeof(int));
        comparisons[selection] = 0;

        start = clock();
        selectionSort(input, sizes[i], &comparisons[selection]);
        end = clock();
        
        test(input, sizes[i], "Selection Sort");
        time = ((double)(end - start))/CLOCKS_PER_SEC;
        fprintf(selectionTime, "%u, %lf\n", sizes[i], time);
        fprintf(selectionComparisons, "%u, %lu\n", sizes[i], comparisons[selection]);
        printf("Completed in %lf seconds\n", time);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

//////////////////////////////////////////////////////// Bubble sort /////////////////////////////////////////////////////////
        printf("\tBubble sort    - ");
        memcpy(input, array, sizes[i]*sizeof(int));
        comparisons[bubble] = 0;

        start = clock();
        bubbleSort(input, sizes[i], &comparisons[bubble]);
        end = clock();
        
        test(input, sizes[i], "Bubble Sort");
        time = ((double)(end - start))/CLOCKS_PER_SEC;
        fprintf(bubbleTime, "%u, %lf\n", sizes[i], time);
        fprintf(bubbleComparisons, "%u, %lu\n", sizes[i], comparisons[bubble]);
        printf("Completed in %lf seconds\n", time);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
        
        printf("----------------------------------------------------------\n");
    }
    free(array);
    free(input);
    fclose(mergeTime);
    fclose(mergeComparisons);
    fclose(quickTime);
    fclose(quickComparisons);
    fclose(selectionTime);
    fclose(selectionComparisons);
    fclose(bubbleTime);
    fclose(bubbleComparisons);
    return 0;
}