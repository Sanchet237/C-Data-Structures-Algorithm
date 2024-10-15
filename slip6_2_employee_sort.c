/*Q.2) Write a C program to read the data from the file “employee.txt” which contains empno and empname and 
sort the data on names alphabetically (use strcmp) using Bubble Sort.*/

#include <stdio.h>
#include <string.h>

struct Employee {
    int eno;
    char ename[50]; 
} e[10], t;

void Display(struct Employee e[], int n) {
    printf("EmpNo\tEmpName\n");
    printf("----------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\n", e[i].eno, e[i].ename);
    }
}

int main() {
    int i, j, n = 0;
    FILE *fp = fopen("Employee.txt", "r");

    if (fp == NULL) {
        printf("Error in opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%d %s", &e[n].eno, e[n].ename) == 2) {
        n++;
        if (n >= 10) {  
            printf("Maximum number of employees reached.\n");
            break;
        }
    }

    fclose(fp);
    
    if (n == 0) {
        printf("No data found in file.\n");
        return 1;
    }

    printf("\nBefore Sort Employee List:\n");
    Display(e, n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i - 1); j++) {
            if (strcmp(e[j].ename, e[j + 1].ename) > 0) {
                t = e[j];
                e[j] = e[j + 1];
                e[j + 1] = t;
            }
        }
    }

    printf("\nAfter Sort Employee List:\n");
    Display(e, n);
    return 0;
}
 /*
 Employee.txt
 
1 Sanchet
2 Gaurav
3 Ajinkya
4 Sumit

 */