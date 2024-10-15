//Q1. Write a C program to sort n numbers using merge sort.

#include <stdio.h>

void merge(int a[], int l, int mid, int r) {
    int t[r - l + 1];
    int i = l;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            t[k] = a[i];
            i++;
        } else {
            t[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        t[k] = a[i];
        i++;
        k++;
    }

    while (j <= r) {
        t[k] = a[j];
        j++;
        k++;
    }

    for (i = l; i <= r; i++) {
        a[i] = t[i - l];
    }
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int a[n]; 
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("Sorted numbers in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
