// This file contains the implementation of the four sorting algorithms
#include "Sort.h"

//////////////////////////////////////////////////////////////////// Merge sort /////////////////////////////////////////////////////////////////////////////////////
void merge(int a[], unsigned int low, unsigned int mid, unsigned int high, unsigned long *comparisons){
    unsigned int i = low, j = mid+1, k = 0;
    while(i <= mid && j <= high){
        *comparisons += 1;         // One element to element comparison
        if(a[i] < a[j]) auxilliary[k++] = a[i++];
        else auxilliary[k++] = a[j++];
        
        #ifdef loop
        *comparisons += 2;         // 2 comparisons in the while loop's condition 
        #endif
    }

    while(i <= mid){                // If the second half part's elements are over, fill the array using the first half's elements (already sorted)
        auxilliary[k++] = a[i++]; 
        #ifdef loop
        *comparisons += 1;          // Comparisons in while loop's conditions
        #endif        
    } 
    while(j <= high){               // If the first half part's elements are over, fill the array using the other half's elements (already sorted)
        auxilliary[k++] = a[j++];        
        #ifdef loop
        *comparisons += 1;          // Comparisons in while loop's conditions
        #endif  
    }
    for(i = 0; i < k; i++){         // A disadvatage of Merge is that it is not an inplace algorithm and needs additional memory to sort the elements  
        a[low++] = auxilliary[i];  
        #ifdef loop
        *comparisons += 1;          // Comparisons in for loop's conditions
        #endif
    } 

    #ifdef loop
    *comparisons += 5;              // Comparisons in above loops' conditions before exiting them
    #endif
}

void mergeSort(int a[], unsigned int low, unsigned int high, unsigned long *comparisons){
    #ifdef loop
    *comparisons += 1; // This is not a direct element to element comparison
    #endif
    if(low < high){
        unsigned int mid = (low+high)/2;
        mergeSort(a, low, mid, comparisons);
        mergeSort(a, mid+1, high, comparisons);
        merge(a, low, mid, high, comparisons);
    }
}


//////////////////////////////////////////////////////////////////// Quick sort /////////////////////////////////////////////////////////////////////////////////////
int partition(int a[], int low, int high, unsigned long *comparisons){    
    int pivot = a[low];                    // Taking the first element of the array as the pivot (Hoare's partition method)
    int i = low+1, j = high;
    while(i <= j){                         // As long as i and j do not cross over
        while(i <= high && a[i] <= pivot){ // Moving i to the right as long as the element a[i] is lesser than the pivot
            i++;
            #ifdef loop
            *comparisons += 1;             // One comparison in the loop's condition
            #endif
            *comparisons += 1;             // One element to element comparison (pivot and ith element)
        }
        while(j > low && a[j] >= pivot){   // Moving j to the left as long as the element a[j] is greater than the pivot
            j--;
            #ifdef loop
            *comparisons += 1;             // One comparison in the loop's condition
            #endif
            *comparisons += 1;             // One element to element comparison (pivot and ith element)
        }
        if(i < j){                         // Swapping a[i] and a[j]
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        #ifdef loop
        *comparisons += 2;                 // One comparison at the while loop's condition and the other at the if statement
        #endif
    }
    if(j != low){                          // Placing the pivot in its right place
            a[low] = a[j];
            a[j] = pivot;
    }
    #ifdef loop
    *comparisons += 1;
    #endif
    return j;
}

void quickSort(int a[], int low, int high, unsigned long *comparisons){  // This is an inplace sorting algorithm, hence it has a better space complexity than merge sort
    #ifdef loop
    *comparisons += 1;
    #endif
    if(low < high){
        int j = partition(a, low, high, comparisons);
        quickSort(a, low, j-1, comparisons);
        quickSort(a, j+1, high, comparisons);
    }
}

////////////////////////////////////////////////////////////////// Selection sort /////////////////////////////////////////////////////////////////////////////////////
void selectionSort(int array[], unsigned int n, unsigned long *comparisons){
    unsigned int min_pos; // Holds the position of the smallest element of each iteration
    for(unsigned int i = 0; i < n-1; i++){ // Selection sort needs to iterate through an 'n' element array a minimum of 'n-1' times
        #ifdef loop
        *comparisons += 1;
        #endif
        min_pos = i; // Start off by assuming the first element of the iteration itself is the smallest element
        for(int j = i + 1; j < n; j++){ // Select the smallest element
            if(array[min_pos] > array[j]) min_pos = j;
            #ifdef loop
            *comparisons += 1;   // One comparison in the loop's condition
            #endif
            *comparisons += 1;   // One element to element comparison (min element and ith element)
        }
        if(i != min_pos) { // Swap if necessary
            int temp = array[min_pos];
            array[min_pos] = array[i];
            array[i] = temp;
        }
        #ifdef loop
        *comparisons += 2;
        #endif
    }
    #ifdef loop
    *comparisons += 1;
    #endif
}

////////////////////////////////////////////////////////////////// Bubble sort /////////////////////////////////////////////////////////////////////////////////////
void bubbleSort(int array[], unsigned int n, unsigned long *comparisons){ // This is a slighlty optimized version of the bubble sort algorithm
    for(unsigned int i = 0; i < n-1; i++){ // Bubble sort needs to iterate through an 'n' element array a maximum of 'n-1' times as at the end of each iteration, 1 element will be at its correct position
        unsigned sorted = 1; // Assuming the array has been sorted
        for(unsigned int j = 0; j < n-1-i; j++){ // The last element is in its right place
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                sorted = 0; // Since a swap has occurred, we cannot be sure that the array is sorted
            }
            #ifdef loop
            *comparisons += 1;   // One comparison in the loop's condition
            #endif
            *comparisons += 1;   // One element to element comparison (jth element and (j+1)th element)
        }
        #ifdef loop
        *comparisons += 3; // One comparison in the loop's condition, one in the if condition and the other at the inner for loop's exit
        #endif
        if(sorted) break; // If no swap occurs, the array has been sorted
    }
    #ifdef loop
    *comparisons += 1;   // One comparison in the loop's condition at exit
    #endif
}


////////////////////////////////////////////////////////////////////// Testing ////////////////////////////////////////////////////////////////////////////////////////
void test(int a[], unsigned int n, char *sort_name){ // This is to check if the algorithms are working fine
    for(unsigned int i = 0; i < n-1; i++) if(a[i] > a[i+1]) printf("Error in %s output!! ", sort_name);
}