/*Q.1) Write a C program to sort an array of structure using bubblesort method. Consider an array of structure Employee with details: emp_id, Name, Address. Sort on emp_id and display
the employee details.*/

#include <stdio.h>
#include <string.h>

struct Employee {
    int eid;
    char ename[20];
    char add[20];
} e[10], t;

void Display(struct Employee e[], int n) {
    printf("EmpID\tEmpName\tEmpAddress\n");
    printf("--------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\n", e[i].eid, e[i].ename, e[i].add);
    }
}

int main() {
    FILE *fp = fopen("employee.txt", "r");
    int i, j, n = 0;

    if (fp == NULL) {
        printf("Error in opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%d %s %s", &e[n].eid, e[n].ename, e[n].add) == 3) {
        n++;
    }
    fclose(fp);

    printf("\nBefore Sort Employee List:\n");
    Display(e, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i - 1); j++) {
            if (e[j].eid > e[j + 1].eid) {
                t = e[j];
                e[j] = e[j + 1];
                e[j + 1] = t;
            }
        }
    }

    printf("\nAfter Sort Employee List (by Employee ID):\n");
    Display(e, n);

    return 0;
}

/*

employee.txt

102 Rohan PUNE
101 Anjali MUMBAI
103 Vikram GOA
*/