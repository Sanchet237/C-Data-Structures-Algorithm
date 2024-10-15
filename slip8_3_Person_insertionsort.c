/*Q.2) Write a C program to read the data from the file “person.txt” which contains person no 
and person age and sort the data on age in ascending order using insertion Sort.*/

#include <stdio.h>
#define MAX 100

void Display(int Pno[], int Page[], int n) {
    printf("P_No\tP_Age\n");
    printf("----------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", Pno[i], Page[i]);
    }
}

int main() {
    int Pno[MAX], Page[MAX];
    int n = 0;
    FILE *fp = fopen("Person.txt", "r");

    if (fp == NULL) {
        printf("Error in opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%d %d", &Pno[n], &Page[n]) == 2) {
        n++;
    }
    fclose(fp);

    if (n == 0) {
        printf("No data found in file.\n");
        return 1;
    }

    printf("\nBefore Insertion Sort Person List\n");
    Display(Pno, Page, n);
    
    for (int i = 1; i < n; i++) {
        int key = Page[i], keyno = Pno[i], j = i - 1;
        while (j >= 0 && Page[j] > key) {
            Page[j + 1] = Page[j];
            Pno[j + 1] = Pno[j];
            j--;
        }
        Page[j + 1] = key;
        Pno[j + 1] = keyno;
    }

    printf("\nAfter Insertion Sort Person List\n");
    Display(Pno, Page, n);
    return 0;
}
 
/*
Person.txt

1 12
2 45
3 46
4 65
5 12

*/