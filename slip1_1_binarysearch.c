//Q.1) Write a C program to search an element by using binary search method.
#include <stdio.h>

#define MAX 100

void bubbleSort(int arr[], int size) 
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int L, int H, int key) 
{
    if (L <= H) 
    {
        int mid = ( L + H )/ 2;

        if (arr[mid] == key) 
            return mid;

        if (arr[mid] < key) 
            return binarySearch(arr, mid + 1, H, key);

        else 
            return binarySearch(arr, L, mid - 1, key);
        
    }
    return -1;
}

int main() 
{
    int n, key, index;
    int arr[MAX];

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Enter the value to search: ");
    scanf("%d", &key);

    index = binarySearch(arr, 0, n - 1, key);

    if (index != -1) {
        printf("Value %d found at index %d.\n", key, index);
    } else {
        printf("Value %d not found in the array.\n", key);
    }

    return 0;
}
