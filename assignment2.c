#include <stdio.h>
#include <time.h>
#include <unistd.h>
void bubbleSort(int a[], int size)
{

    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - (i + 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}    
void merge(int a[], int left, int m, int right)
{
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;

    // Create temp arrays 
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    // Merge the temp arrays back into a[left..right]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if thereare any 
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

// left is for left index and right is right index of the sub-array of a to be sorted 
void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for large left and h
        int m = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(a, left, m);
        mergeSort(a, m + 1, right);

        merge(a, left, m, right);
    }
}
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  \n", arr[i]);
    }
}
int main()
{
    int max_size = 10;
    int A_Bubble[10] = {1,3,42,2,41,66,66,33,98,0}, A_Merge[10] = {1,3,42,2,41,66,66,33,98,0};
    // Time calculation 
    float milliSec;
    clock_t start, stop;
     start = clock();  // for starting the time calculation for bubble sort
    bubbleSort(A_Bubble,max_size);
    printf("The sorted array is\n");
    printArray(A_Bubble, max_size);
    sleep(1);
    stop = clock(); //for ending the time calculation for bubble sort
    milliSec= ((double)(stop-start)/CLOCKS_PER_SEC)*1000; //time in milliseconds
  
    printf("bubble sorting took %f milliseconds to execute \n", milliSec);
    printf("\n\n--------------------------------\n\n");
    start = clock(); // for starting the time calculation for merge sort
    mergeSort(A_Merge, 0, ( max_size- 1));
    printf("The sorted array is\n");
    printArray(A_Merge , max_size);
    sleep(1);
    stop = clock(); // for ending the time calculation for merge sort
    milliSec = ((double)(stop-start) / CLOCKS_PER_SEC)*1000; // time in milliseconds
    printf("merge sorting took %f milliseconds  to execute \n", milliSec);
    return 0;
}