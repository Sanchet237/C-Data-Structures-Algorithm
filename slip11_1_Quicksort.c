//Q.1) Write a C program to sort n elements using QuickSort.
#include<stdio.h>

int Partition(int a[], int lb, int rb) {
    int R, L, temp, Pivot;
    R = rb;
    L = lb+1;
    Pivot = a[lb];

    do {
        while ((a[L] < Pivot) && (L <= rb)) L++;
        while ((a[R] > Pivot) && (R > lb)) R--;
        
        if (L < R) {
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;
        }
    } while (L < R);

    a[lb] = a[R];
    a[R] = Pivot;

    return R;
}

void QuickSort(int a[], int lb, int rb) {
    int j;
    if (lb < rb) {
        j = Partition(a, lb, rb);
        QuickSort(a, lb, j-1);
        QuickSort(a, j+1, rb);
    }
}



void main() 
{
    int a[20], i, n;

    printf("Enter the size of the array : ");
    scanf("%d", &n);
	printf("\nEnter %d array elements\n",n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    QuickSort(a, 0, n-1);

    printf("\n Sorted list in Ascennding order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
