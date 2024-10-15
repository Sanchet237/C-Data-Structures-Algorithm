//Q.1) Write a C program to sort n numbers using insertion sort integers.

#include <stdio.h>
#define MAX 100

void insertionSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 1; i < n; i++) 
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() 
{
    int arr[MAX];
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    printf("\nEnter %d integers\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("\nSorted array in ascending order\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
